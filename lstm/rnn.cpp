#include <iostream>
#include <cmath>
#include <string.h>
#include "rnn.h"
#include "weight.h"


// �����������ĳ˷�

//#define gemvm1(res, a, b, row, col) \
//{ \
//	std::fill_n(res, row, 0.0); \
//	for (int r = 0; r < row; r++) \
//		for (int c = 0; c < col; c++) \
//			res[r] += a[r][c] * b[c]; \
//}


inline void gemvm(float res[HIDDEN_DIM], float a[HIDDEN_DIM][INPUT_DIM + HIDDEN_DIM], float b[INPUT_DIM + HIDDEN_DIM])
{
	loop_outer:
	for (int r = 0; r < HIDDEN_DIM; r++)
	{
#pragma HLS PIPELINE
		loop_iner:
		for (int c = 0; c < INPUT_DIM + HIDDEN_DIM; c++)
		{
#pragma HLS PIPELINE
			res[r] += a[r][c] * b[c];
		}
	}
}

inline void gemvm1(float res[CLASS_NUM], float a[CLASS_NUM][HIDDEN_DIM], float b[HIDDEN_DIM])
{
	loop_outer:
	for (int r = 0; r < CLASS_NUM; r++)
	{
#pragma HLS PIPELINE
		loop_iner:
		for (int c = 0; c < HIDDEN_DIM; c++)
		{
#pragma HLS PIPELINE
			res[r] += a[r][c] * b[c];
		}
	}
}


////void matrix_mul(ap_int<8> A[4][4],ap_int<8> B[4][4],ap_int<16> C[4][4],int row, int col)
//{
//	for(int i=0;i<4;i++)
//	{
//
//		for(int j=0;j<4;j++)
//		{
//
//			C[i][j]=0;
//			for(int k=0;k<4;k++)
//			{
//				C[i][j]=C[i][j]+A[i][k]*B[k][j];
//			}
//		}
//	}
//}



// ������sigmoid����
inline void sigmoid(float* res, float* a, int size)
{
	// ������������a��sigmoid����ֵ
	// �������洢������res��
	// TODO:
	int i;
	i_loop:for (i = 0;i < size; i++)
	{
#pragma HLS PIPELINE
		res[i] = (1 / (1 + exp(-a[i])));
	}
}

// ������tanh����
inline void tanh(float* res, float* a, int size)
{
	// ������������a��˫�����к���ֵ
	// �������洢������res��
	// TODO:
	int i;
	i_loop:for (i = 0;i < size; i++)
	{
#pragma HLS unroll factor = 2
#pragma HLS PIPELINE
		res[i] =( (exp(a[i]) - exp(-a[i])) / (exp(a[i]) + exp(-a[i])));
	}
}

// �����ӷ�
inline void geva(float* res, float* a, int size)
{
	// ������res������a���
	// �������洢������res��
	// TODO:
	int i;
	i_loop:for (i = 0;i < size; i++)
	{
		#pragma HLS unroll factor = 2
		#pragma HLS PIPELINE II = 1
		res[i] += a[i];
	}
}

// ������Hadamard��
inline void hprod(float* res, float* a, float* b, int size)
{
	// ��������a������b��Hadamard��
	// �������洢������res��
	// TODO:
	int i;
	i_loop:	for (i = 0;i < size; i++)
	{
#pragma HLS unroll factor = 2
#pragma HLS PIPELINE II = 1
		res[i] =( a[i] * b[i]);
	}
	
}

// RNNǰ���Ƶ�(�����->LSTM->���Է�����)
#if CSIM_ON == 1
int infer(float input[IMG_SIZE])
#else
void infer(float input[IMG_SIZE], float res[CLASS_NUM])
#endif
{
	float gate_f[HIDDEN_DIM] = { 0.0 };		// LSTM cell�������ſ�������
	float gate_i[HIDDEN_DIM] = { 0.0 };		// LSTM cell�������ſ�������
	float stat_C[HIDDEN_DIM] = { 0.0 };		// LSTM cell����״̬
	float C_t[HIDDEN_DIM] = { 0.0 };		// LSTM cell��״̬
	float gate_o[HIDDEN_DIM] = { 0.0 };		// LSTM cell������ſ�������
	float h_t[HIDDEN_DIM] = { 0.0 };		// LSTM cell�����

	float vec_i[INPUT_DIM + HIDDEN_DIM];	// LSTM cell����������[x(t), h0(t-1)]
	float vec_tmp[HIDDEN_DIM];				// �м����

	// �����->���ز�(LSTM cell)
	for (int i = 0; i < INPUT_DIM; i++)
	{
		/*
		 * ͷ�ļ�weight.h�д洢��RNN�����Ȩֵ��ƫ��, �������¼���FP32����:
		 *
		 * 1. LSTM cell�����ŵ�Ȩֵ��ƫ��:
		 *   float Weight0_f[HIDDEN_DIM][INPUT_DIM + HIDDEN_DIM];
		 *   float Bias0_f[HIDDEN_DIM];
		 *
		 * 2. LSTM cell�����ŵ�Ȩֵ��ƫ��:
		 *   float Weight0_i[HIDDEN_DIM][INPUT_DIM + HIDDEN_DIM];
		 *   float Bias0_i[HIDDEN_DIM];
		 *
		 * 3. LSTM cell�����Ų����ĺ�ѡ״̬��Ȩֵ��ƫ��:
		 *   float Weight0_c[HIDDEN_DIM][INPUT_DIM + HIDDEN_DIM];
		 *   float Bias0_c[HIDDEN_DIM];
		 *
		 * 4. LSTM cell����ŵ�Ȩֵ��ƫ��:
		 *   float Weight0_o[HIDDEN_DIM][INPUT_DIM + HIDDEN_DIM];
		 *   float Bias0_o[HIDDEN_DIM];
		 *
		 * 5. ��������Է�������Ȩֵ��ƫ��:
		 *   float Weight_lc[CLASS_NUM][HIDDEN_DIM];
		 *   float Bias_lc[CLASS_NUM];
		 * */

		// ����LSTM cell0����������
		for (int j = 0; j < INPUT_DIM; j++)		vec_i[j] = input[i * INPUT_DIM + j];
		for (int j = 0; j < HIDDEN_DIM; j++)	vec_i[INPUT_DIM + j] = h_t[j];


		loop_reigion:
		{
		/*
		 * 1. ����LSTM cell�������ſ�������.
		 * */
		// TODO:

		LF:
		gemvm(vec_tmp, Weight0_f, vec_i);
//		gemvm(vec_tmp, Weight0_f, vec_i, HIDDEN_DIM, INPUT_DIM + HIDDEN_DIM);
		geva(vec_tmp, Bias0_f, HIDDEN_DIM);
		sigmoid(gate_f, vec_tmp, HIDDEN_DIM);

		/*
		 * 2. ����LSTM cell�������ſ�������.
		 * */
		// TODO:
		LI:
		gemvm(vec_tmp, Weight0_i, vec_i);
//		gemvm(vec_tmp, Weight0_i, vec_i, HIDDEN_DIM, INPUT_DIM + HIDDEN_DIM);
		geva(vec_tmp, Bias0_i, HIDDEN_DIM);
		sigmoid(gate_i, vec_tmp, HIDDEN_DIM);

		/*
		 * 3. ����LSTM cell�����Ų����ĺ�ѡ״̬����
		 * */
		// TODO:
		LC:
//		gemvm(vec_tmp, Weight0_c, vec_i, HIDDEN_DIM, INPUT_DIM + HIDDEN_DIM);
		gemvm(vec_tmp, Weight0_c, vec_i);
		geva(vec_tmp, Bias0_c, HIDDEN_DIM);
		tanh(stat_C, vec_tmp, HIDDEN_DIM);
		}
		/*
		 * 4. ����LSTM cell������ſ�������.
		 * */
		// TODO:
		LO:
//		gemvm(vec_tmp, Weight0_o, vec_i, HIDDEN_DIM, INPUT_DIM + HIDDEN_DIM);
		gemvm(vec_tmp, Weight0_o, vec_i);
		geva(vec_tmp, Bias0_o, HIDDEN_DIM);
		sigmoid(gate_o, vec_tmp, HIDDEN_DIM);

		/*
		 * 5. ����LSTM cell����״̬.
		 * */
		// TODO:
		LCT:
		hprod(vec_tmp, gate_f, C_t, HIDDEN_DIM);
		hprod(C_t, gate_i, stat_C, HIDDEN_DIM);
		geva(C_t, vec_tmp,HIDDEN_DIM);

		/*
		 * 6. ����LSTM cell�����.
		 * */
		// TODO:
		LH:
		tanh(vec_tmp, C_t, HIDDEN_DIM);
		hprod(h_t, gate_o, vec_tmp, HIDDEN_DIM);



	}

#if CSIM_ON == 1
	float res[CLASS_NUM];
#endif

	// ���ز�(LSTM cell)->�����(���Է�����)

//	gemvm1(res, Weight_lc, h_t);
	gemvm1(res, Weight_lc, h_t);
	geva(res, Bias_lc, CLASS_NUM);

#if CSIM_ON == 1
	int label = 0;
	for (int i = 1; i < CLASS_NUM; i++)

if (res[i] > res[label]) label = i;

	return label;
#endif
}
