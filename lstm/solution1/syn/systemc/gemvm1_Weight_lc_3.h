// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __gemvm1_Weight_lc_3_H__
#define __gemvm1_Weight_lc_3_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct gemvm1_Weight_lc_3_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 5;
  static const unsigned AddressWidth = 3;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(gemvm1_Weight_lc_3_ram) {
        ram[0] = "0b00111101111001001000111111011010";
        ram[1] = "0b10111110000000010000010111110010";
        ram[2] = "0b10111100110100100111010101111000";
        ram[3] = "0b00111100111110111101001100100000";
        ram[4] = "0b10111101101010000101101100011000";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(gemvm1_Weight_lc_3) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 5;
static const unsigned AddressWidth = 3;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


gemvm1_Weight_lc_3_ram* meminst;


SC_CTOR(gemvm1_Weight_lc_3) {
meminst = new gemvm1_Weight_lc_3_ram("gemvm1_Weight_lc_3_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~gemvm1_Weight_lc_3() {
    delete meminst;
}


};//endmodule
#endif
