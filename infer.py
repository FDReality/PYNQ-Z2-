import time
import torch
from torch.utils.data import Dataset,DataLoader
from torch import nn
from torch.autograd import Variable
from torchvision import transforms
from torchvision import datasets
import image_processing
import numpy as np
import os

class TorchDataset(Dataset):
    def __init__(self, filename, image_dir, resize_height=28, resize_width=28, repeat=1):
        '''
        :param filename: 数据文件TXT：格式：imge_name.jpg label1_id labe2_id
        :param image_dir: 图片路径：image_dir+imge_name.jpg构成图片的完整路径
        :param resize_height 为None时，不进行缩放
        :param resize_width  为None时，不进行缩放，
                              PS：当参数resize_height或resize_width其中一个为None时，可实现等比例缩放
        :param repeat: 所有样本数据重复次数，默认循环一次，当repeat为None时，表示无限循环<sys.maxsize
        '''
        self.image_label_list = self.read_file(filename)
        self.image_dir = image_dir
        self.len = len(self.image_label_list)
        self.repeat = repeat
        self.resize_height = resize_height
        self.resize_width = resize_width

        # 相关预处理的初始化
        '''class torchvision.transforms.ToTensor'''
        # 把shape=(H,W,C)的像素值范围为[0, 255]的PIL.Image或者numpy.ndarray数据
        # 转换成shape=(C,H,W)的像素数据，并且被归一化到[0.0, 1.0]的torch.FloatTensor类型。
        self.toTensor = transforms.ToTensor()

        '''class torchvision.transforms.Normalize(mean, std)
        此转换类作用于torch. * Tensor,给定均值(R, G, B) 和标准差(R, G, B)，
        用公式channel = (channel - mean) / std进行规范化。
        '''
        # self.normalize=transforms.Normalize()

    def __getitem__(self, i):
        index = i % self.len
        # print("i={},index={}".format(i, index))
        image_name, label = self.image_label_list[index]
        image_path = os.path.join(self.image_dir, image_name)
        img = self.load_data(image_path, self.resize_height, self.resize_width, normalization=False)
        img = self.data_preproccess(img)
        label = np.array(label)
        label = torch.Tensor(label).long()
        return img, label

    def __len__(self):
        if self.repeat == None:
            data_len = 10000000
        else:
            data_len = len(self.image_label_list) * self.repeat
        return data_len

    def read_file(self, filename):
        image_label_list = []
        with open(filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                # rstrip：用来去除结尾字符、空白符(包括\n、\r、\t、' '，即：换行、回车、制表符、空格)
                content = line.rstrip().split(' ')
                name = content[0]
                labels = []
                for value in content[1:]:
                    labels.append(int(value))
                image_label_list.append((name, labels))
        return image_label_list

    def load_data(self, path, resize_height, resize_width, normalization):
        '''
        加载数据
        :param path:
        :param resize_height:
        :param resize_width:
        :param normalization: 是否归一化
        :return:
        '''
        image = image_processing.read_image(path, resize_height, resize_width, normalization)
        return image

    def data_preproccess(self, data):
        '''
        数据预处理
        :param data:
        :return:
        '''
        data = self.toTensor(data)
        return data
#将数据集导入DataLoader，进行shuffle以及选取batch_size
# data_loader = DataLoader(data,batch_size=2,shuffle=True,num_workers=0)
#Windows里num_works只能为0，其他值会报错
# for pics,label in data_loader:
#     print(pics,label)

# 定义超参数
batch_size = 128
learning_rate = 1e-3
num_epoches = 20


#路径是自己电脑里所对应的路径
datapath = r'C:\Users\fd_reality\Desktop\Ceshi\test'
txt_path = r'C:\Users\fd_reality\Desktop\Ceshi\test.txt'
# 准备训练集
test_data = TorchDataset(filename=txt_path, image_dir=datapath,repeat=1)
test_loader = DataLoader(test_data, batch_size=batch_size, shuffle=True, num_workers=0)


# 定义 Recurrent Network 模型
class Rnn(nn.Module):
    def __init__(self, in_dim, hidden_dim, n_layer, n_class):
        super(Rnn, self).__init__()
        self.n_layer = n_layer
        self.hidden_dim = hidden_dim
        self.lstm = nn.LSTM(in_dim, hidden_dim, n_layer, batch_first=True)
        self.classifier = nn.Linear(hidden_dim, n_class)
        
    def forward(self, x):
        out, _ = self.lstm(x)
        out = out[:, -1, :]
        out = self.classifier(out)
        return out

if __name__ == '__main__':
    # Use pretrained model
    model = Rnn(28, 64, 1, 5) # 图片大小是28x28
    model.load_state_dict(torch.load('C:/Users/fd_reality/Desktop/Ceshi/weight.pth'))
    print(model)

    criterion = nn.CrossEntropyLoss()
    model.eval()
    eval_loss = 0.0
    eval_acc = 0.0

    t0 = time.time()
    # 开始测试
    for data in test_loader:
        img, label = data
        _, c, _, _ = img.size()
        assert c == 1, 'channel must be 1'
        img = img.squeeze(1)
        img = Variable(img)
        label = Variable(label)
        label = label.squeeze(dim=1)
        out = model(img)
        loss = criterion(out, label)
        eval_loss += loss.data.item() * label.size(0)
        _, pred = torch.max(out, 1)
        num_correct = (pred == label).sum()
        eval_acc += num_correct.data.item()
        # print(img)
        # print()
        # print(label)
        # print()
        # print(out)
        # break
    
    t1 = time.time()
    print('{} images tested in {:.3f}s'.format(len(test_data), t1 - t0))
    print('Test Loss: {:.6f}, Acc: {:.6f}'.format(
        eval_loss / (len(test_data)), eval_acc / (len(test_data))))
