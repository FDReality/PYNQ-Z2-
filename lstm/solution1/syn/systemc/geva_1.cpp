// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "geva_1.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic geva_1::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic geva_1::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<4> geva_1::ap_ST_fsm_state1 = "1";
const sc_lv<4> geva_1::ap_ST_fsm_pp0_stage0 = "10";
const sc_lv<4> geva_1::ap_ST_fsm_pp0_stage1 = "100";
const sc_lv<4> geva_1::ap_ST_fsm_state12 = "1000";
const bool geva_1::ap_const_boolean_1 = true;
const sc_lv<32> geva_1::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> geva_1::ap_const_lv32_1 = "1";
const bool geva_1::ap_const_boolean_0 = false;
const sc_lv<1> geva_1::ap_const_lv1_0 = "0";
const sc_lv<32> geva_1::ap_const_lv32_2 = "10";
const sc_lv<1> geva_1::ap_const_lv1_1 = "1";
const sc_lv<7> geva_1::ap_const_lv7_0 = "0000000";
const sc_lv<32> geva_1::ap_const_lv32_6 = "110";
const sc_lv<6> geva_1::ap_const_lv6_1 = "1";
const sc_lv<7> geva_1::ap_const_lv7_2 = "10";
const sc_lv<32> geva_1::ap_const_lv32_3 = "11";

geva_1::geva_1(sc_module_name name) : sc_module(name), mVcdFile(0) {
    LSTM_Top_fadd_32nbkb_U10 = new LSTM_Top_fadd_32nbkb<1,5,32,32,32>("LSTM_Top_fadd_32nbkb_U10");
    LSTM_Top_fadd_32nbkb_U10->clk(ap_clk);
    LSTM_Top_fadd_32nbkb_U10->reset(ap_rst);
    LSTM_Top_fadd_32nbkb_U10->din0(grp_fu_98_p0);
    LSTM_Top_fadd_32nbkb_U10->din1(grp_fu_98_p1);
    LSTM_Top_fadd_32nbkb_U10->ce(ap_var_for_const0);
    LSTM_Top_fadd_32nbkb_U10->dout(grp_fu_98_p2);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_a_address0);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( zext_ln109_fu_114_p1 );

    SC_METHOD(thread_a_address1);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( zext_ln109_1_fu_126_p1 );

    SC_METHOD(thread_a_ce0);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_enable_reg_pp0_iter0 );

    SC_METHOD(thread_a_ce1);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_enable_reg_pp0_iter0 );

    SC_METHOD(thread_add_ln105_fu_132_p2);
    sensitive << ( i_0_0_reg_86 );

    SC_METHOD(thread_ap_CS_fsm_pp0_stage0);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_pp0_stage1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state12);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_block_pp0_stage0);

    SC_METHOD(thread_ap_block_pp0_stage0_11001);

    SC_METHOD(thread_ap_block_pp0_stage0_subdone);

    SC_METHOD(thread_ap_block_pp0_stage1);

    SC_METHOD(thread_ap_block_pp0_stage1_11001);

    SC_METHOD(thread_ap_block_pp0_stage1_subdone);

    SC_METHOD(thread_ap_block_state10_pp0_stage0_iter4);

    SC_METHOD(thread_ap_block_state11_pp0_stage1_iter4);

    SC_METHOD(thread_ap_block_state2_pp0_stage0_iter0);

    SC_METHOD(thread_ap_block_state3_pp0_stage1_iter0);

    SC_METHOD(thread_ap_block_state4_pp0_stage0_iter1);

    SC_METHOD(thread_ap_block_state5_pp0_stage1_iter1);

    SC_METHOD(thread_ap_block_state6_pp0_stage0_iter2);

    SC_METHOD(thread_ap_block_state7_pp0_stage1_iter2);

    SC_METHOD(thread_ap_block_state8_pp0_stage0_iter3);

    SC_METHOD(thread_ap_block_state9_pp0_stage1_iter3);

    SC_METHOD(thread_ap_condition_pp0_exit_iter0_state2);
    sensitive << ( tmp_2_fu_102_p3 );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state12 );

    SC_METHOD(thread_ap_enable_pp0);
    sensitive << ( ap_idle_pp0 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_idle_pp0);
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_enable_reg_pp0_iter3 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_enable_reg_pp0_iter2 );
    sensitive << ( ap_enable_reg_pp0_iter4 );

    SC_METHOD(thread_ap_phi_mux_i_0_0_phi_fu_90_p4);
    sensitive << ( i_0_0_reg_86 );
    sensitive << ( tmp_2_reg_138 );
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( add_ln105_reg_182 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage0 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state12 );

    SC_METHOD(thread_grp_fu_98_p0);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( res_load_reg_167 );
    sensitive << ( res_load_1_reg_177 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage1 );

    SC_METHOD(thread_grp_fu_98_p1);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( a_load_reg_162 );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( a_load_1_reg_172 );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage1 );

    SC_METHOD(thread_or_ln105_fu_120_p2);
    sensitive << ( trunc_ln105_fu_110_p1 );

    SC_METHOD(thread_res_address0);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( res_addr_reg_147_pp0_iter3_reg );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_enable_reg_pp0_iter3 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( zext_ln109_fu_114_p1 );
    sensitive << ( ap_block_pp0_stage1 );

    SC_METHOD(thread_res_address1);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( res_addr_3_reg_157_pp0_iter4_reg );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_enable_reg_pp0_iter4 );
    sensitive << ( ap_block_pp0_stage0 );
    sensitive << ( zext_ln109_1_fu_126_p1 );
    sensitive << ( ap_block_pp0_stage1 );

    SC_METHOD(thread_res_ce0);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_block_pp0_stage1_11001 );
    sensitive << ( ap_enable_reg_pp0_iter3 );

    SC_METHOD(thread_res_ce1);
    sensitive << ( ap_CS_fsm_pp0_stage0 );
    sensitive << ( ap_block_pp0_stage0_11001 );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_block_pp0_stage1_11001 );
    sensitive << ( ap_enable_reg_pp0_iter4 );

    SC_METHOD(thread_res_d0);
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( tmp8_reg_187 );
    sensitive << ( ap_enable_reg_pp0_iter3 );
    sensitive << ( ap_block_pp0_stage1 );

    SC_METHOD(thread_res_d1);
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( tmp_1_reg_192 );
    sensitive << ( ap_enable_reg_pp0_iter4 );
    sensitive << ( ap_block_pp0_stage1 );

    SC_METHOD(thread_res_we0);
    sensitive << ( tmp_2_reg_138_pp0_iter3_reg );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_block_pp0_stage1_11001 );
    sensitive << ( ap_enable_reg_pp0_iter3 );

    SC_METHOD(thread_res_we1);
    sensitive << ( tmp_2_reg_138_pp0_iter4_reg );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_block_pp0_stage1_11001 );
    sensitive << ( ap_enable_reg_pp0_iter4 );

    SC_METHOD(thread_tmp_2_fu_102_p3);
    sensitive << ( ap_phi_mux_i_0_0_phi_fu_90_p4 );

    SC_METHOD(thread_trunc_ln105_fu_110_p1);
    sensitive << ( ap_phi_mux_i_0_0_phi_fu_90_p4 );

    SC_METHOD(thread_zext_ln109_1_fu_126_p1);
    sensitive << ( or_ln105_fu_120_p2 );

    SC_METHOD(thread_zext_ln109_fu_114_p1);
    sensitive << ( ap_phi_mux_i_0_0_phi_fu_90_p4 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( tmp_2_fu_102_p3 );
    sensitive << ( ap_CS_fsm_pp0_stage1 );
    sensitive << ( ap_enable_reg_pp0_iter0 );
    sensitive << ( ap_enable_reg_pp0_iter3 );
    sensitive << ( ap_block_pp0_stage0_subdone );
    sensitive << ( ap_enable_reg_pp0_iter1 );
    sensitive << ( ap_block_pp0_stage1_subdone );
    sensitive << ( ap_enable_reg_pp0_iter4 );

    SC_THREAD(thread_ap_var_for_const0);

    ap_CS_fsm = "0001";
    ap_enable_reg_pp0_iter0 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter3 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter1 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter2 = SC_LOGIC_0;
    ap_enable_reg_pp0_iter4 = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "geva_1_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, res_address0, "(port)res_address0");
    sc_trace(mVcdFile, res_ce0, "(port)res_ce0");
    sc_trace(mVcdFile, res_we0, "(port)res_we0");
    sc_trace(mVcdFile, res_d0, "(port)res_d0");
    sc_trace(mVcdFile, res_q0, "(port)res_q0");
    sc_trace(mVcdFile, res_address1, "(port)res_address1");
    sc_trace(mVcdFile, res_ce1, "(port)res_ce1");
    sc_trace(mVcdFile, res_we1, "(port)res_we1");
    sc_trace(mVcdFile, res_d1, "(port)res_d1");
    sc_trace(mVcdFile, res_q1, "(port)res_q1");
    sc_trace(mVcdFile, a_address0, "(port)a_address0");
    sc_trace(mVcdFile, a_ce0, "(port)a_ce0");
    sc_trace(mVcdFile, a_q0, "(port)a_q0");
    sc_trace(mVcdFile, a_address1, "(port)a_address1");
    sc_trace(mVcdFile, a_ce1, "(port)a_ce1");
    sc_trace(mVcdFile, a_q1, "(port)a_q1");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, i_0_0_reg_86, "i_0_0_reg_86");
    sc_trace(mVcdFile, tmp_2_fu_102_p3, "tmp_2_fu_102_p3");
    sc_trace(mVcdFile, tmp_2_reg_138, "tmp_2_reg_138");
    sc_trace(mVcdFile, ap_CS_fsm_pp0_stage0, "ap_CS_fsm_pp0_stage0");
    sc_trace(mVcdFile, ap_block_state2_pp0_stage0_iter0, "ap_block_state2_pp0_stage0_iter0");
    sc_trace(mVcdFile, ap_block_state4_pp0_stage0_iter1, "ap_block_state4_pp0_stage0_iter1");
    sc_trace(mVcdFile, ap_block_state6_pp0_stage0_iter2, "ap_block_state6_pp0_stage0_iter2");
    sc_trace(mVcdFile, ap_block_state8_pp0_stage0_iter3, "ap_block_state8_pp0_stage0_iter3");
    sc_trace(mVcdFile, ap_block_state10_pp0_stage0_iter4, "ap_block_state10_pp0_stage0_iter4");
    sc_trace(mVcdFile, ap_block_pp0_stage0_11001, "ap_block_pp0_stage0_11001");
    sc_trace(mVcdFile, tmp_2_reg_138_pp0_iter1_reg, "tmp_2_reg_138_pp0_iter1_reg");
    sc_trace(mVcdFile, tmp_2_reg_138_pp0_iter2_reg, "tmp_2_reg_138_pp0_iter2_reg");
    sc_trace(mVcdFile, tmp_2_reg_138_pp0_iter3_reg, "tmp_2_reg_138_pp0_iter3_reg");
    sc_trace(mVcdFile, tmp_2_reg_138_pp0_iter4_reg, "tmp_2_reg_138_pp0_iter4_reg");
    sc_trace(mVcdFile, res_addr_reg_147, "res_addr_reg_147");
    sc_trace(mVcdFile, res_addr_reg_147_pp0_iter1_reg, "res_addr_reg_147_pp0_iter1_reg");
    sc_trace(mVcdFile, res_addr_reg_147_pp0_iter2_reg, "res_addr_reg_147_pp0_iter2_reg");
    sc_trace(mVcdFile, res_addr_reg_147_pp0_iter3_reg, "res_addr_reg_147_pp0_iter3_reg");
    sc_trace(mVcdFile, res_addr_3_reg_157, "res_addr_3_reg_157");
    sc_trace(mVcdFile, res_addr_3_reg_157_pp0_iter1_reg, "res_addr_3_reg_157_pp0_iter1_reg");
    sc_trace(mVcdFile, res_addr_3_reg_157_pp0_iter2_reg, "res_addr_3_reg_157_pp0_iter2_reg");
    sc_trace(mVcdFile, res_addr_3_reg_157_pp0_iter3_reg, "res_addr_3_reg_157_pp0_iter3_reg");
    sc_trace(mVcdFile, res_addr_3_reg_157_pp0_iter4_reg, "res_addr_3_reg_157_pp0_iter4_reg");
    sc_trace(mVcdFile, a_load_reg_162, "a_load_reg_162");
    sc_trace(mVcdFile, ap_CS_fsm_pp0_stage1, "ap_CS_fsm_pp0_stage1");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter0, "ap_enable_reg_pp0_iter0");
    sc_trace(mVcdFile, ap_block_state3_pp0_stage1_iter0, "ap_block_state3_pp0_stage1_iter0");
    sc_trace(mVcdFile, ap_block_state5_pp0_stage1_iter1, "ap_block_state5_pp0_stage1_iter1");
    sc_trace(mVcdFile, ap_block_state7_pp0_stage1_iter2, "ap_block_state7_pp0_stage1_iter2");
    sc_trace(mVcdFile, ap_block_state9_pp0_stage1_iter3, "ap_block_state9_pp0_stage1_iter3");
    sc_trace(mVcdFile, ap_block_state11_pp0_stage1_iter4, "ap_block_state11_pp0_stage1_iter4");
    sc_trace(mVcdFile, ap_block_pp0_stage1_11001, "ap_block_pp0_stage1_11001");
    sc_trace(mVcdFile, res_load_reg_167, "res_load_reg_167");
    sc_trace(mVcdFile, a_load_1_reg_172, "a_load_1_reg_172");
    sc_trace(mVcdFile, res_load_1_reg_177, "res_load_1_reg_177");
    sc_trace(mVcdFile, add_ln105_fu_132_p2, "add_ln105_fu_132_p2");
    sc_trace(mVcdFile, add_ln105_reg_182, "add_ln105_reg_182");
    sc_trace(mVcdFile, grp_fu_98_p2, "grp_fu_98_p2");
    sc_trace(mVcdFile, tmp8_reg_187, "tmp8_reg_187");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter3, "ap_enable_reg_pp0_iter3");
    sc_trace(mVcdFile, tmp_1_reg_192, "tmp_1_reg_192");
    sc_trace(mVcdFile, ap_block_pp0_stage0_subdone, "ap_block_pp0_stage0_subdone");
    sc_trace(mVcdFile, ap_condition_pp0_exit_iter0_state2, "ap_condition_pp0_exit_iter0_state2");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter1, "ap_enable_reg_pp0_iter1");
    sc_trace(mVcdFile, ap_block_pp0_stage1_subdone, "ap_block_pp0_stage1_subdone");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter2, "ap_enable_reg_pp0_iter2");
    sc_trace(mVcdFile, ap_enable_reg_pp0_iter4, "ap_enable_reg_pp0_iter4");
    sc_trace(mVcdFile, ap_phi_mux_i_0_0_phi_fu_90_p4, "ap_phi_mux_i_0_0_phi_fu_90_p4");
    sc_trace(mVcdFile, ap_block_pp0_stage0, "ap_block_pp0_stage0");
    sc_trace(mVcdFile, zext_ln109_fu_114_p1, "zext_ln109_fu_114_p1");
    sc_trace(mVcdFile, zext_ln109_1_fu_126_p1, "zext_ln109_1_fu_126_p1");
    sc_trace(mVcdFile, ap_block_pp0_stage1, "ap_block_pp0_stage1");
    sc_trace(mVcdFile, grp_fu_98_p0, "grp_fu_98_p0");
    sc_trace(mVcdFile, grp_fu_98_p1, "grp_fu_98_p1");
    sc_trace(mVcdFile, trunc_ln105_fu_110_p1, "trunc_ln105_fu_110_p1");
    sc_trace(mVcdFile, or_ln105_fu_120_p2, "or_ln105_fu_120_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state12, "ap_CS_fsm_state12");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
    sc_trace(mVcdFile, ap_idle_pp0, "ap_idle_pp0");
    sc_trace(mVcdFile, ap_enable_pp0, "ap_enable_pp0");
#endif

    }
}

geva_1::~geva_1() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete LSTM_Top_fadd_32nbkb_U10;
}

void geva_1::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_logic_1;
}

void geva_1::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp0_exit_iter0_state2.read()))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter1 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0))) {
            ap_enable_reg_pp0_iter1 = ap_enable_reg_pp0_iter0.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter2 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0))) {
            ap_enable_reg_pp0_iter2 = ap_enable_reg_pp0_iter1.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter3 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0))) {
            ap_enable_reg_pp0_iter3 = ap_enable_reg_pp0_iter2.read();
        }
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter4 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0))) {
            ap_enable_reg_pp0_iter4 = ap_enable_reg_pp0_iter3.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            ap_enable_reg_pp0_iter4 = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(tmp_2_reg_138.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        i_0_0_reg_86 = add_ln105_reg_182.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        i_0_0_reg_86 = ap_const_lv7_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_2_reg_138.read(), ap_const_lv1_0))) {
        a_load_1_reg_172 = a_q1.read();
        a_load_reg_162 = a_q0.read();
        add_ln105_reg_182 = add_ln105_fu_132_p2.read();
        res_load_1_reg_177 = res_q1.read();
        res_load_reg_167 = res_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_2_fu_102_p3.read(), ap_const_lv1_0))) {
        res_addr_3_reg_157 =  (sc_lv<6>) (zext_ln109_1_fu_126_p1.read());
        res_addr_reg_147 =  (sc_lv<6>) (zext_ln109_fu_114_p1.read());
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        res_addr_3_reg_157_pp0_iter1_reg = res_addr_3_reg_157.read();
        res_addr_3_reg_157_pp0_iter2_reg = res_addr_3_reg_157_pp0_iter1_reg.read();
        res_addr_3_reg_157_pp0_iter3_reg = res_addr_3_reg_157_pp0_iter2_reg.read();
        res_addr_3_reg_157_pp0_iter4_reg = res_addr_3_reg_157_pp0_iter3_reg.read();
        res_addr_reg_147_pp0_iter1_reg = res_addr_reg_147.read();
        res_addr_reg_147_pp0_iter2_reg = res_addr_reg_147_pp0_iter1_reg.read();
        res_addr_reg_147_pp0_iter3_reg = res_addr_reg_147_pp0_iter2_reg.read();
        tmp_2_reg_138 = ap_phi_mux_i_0_0_phi_fu_90_p4.read().range(6, 6);
        tmp_2_reg_138_pp0_iter1_reg = tmp_2_reg_138.read();
        tmp_2_reg_138_pp0_iter2_reg = tmp_2_reg_138_pp0_iter1_reg.read();
        tmp_2_reg_138_pp0_iter3_reg = tmp_2_reg_138_pp0_iter2_reg.read();
        tmp_2_reg_138_pp0_iter4_reg = tmp_2_reg_138_pp0_iter3_reg.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter3.read()) && esl_seteq<1,1,1>(tmp_2_reg_138_pp0_iter2_reg.read(), ap_const_lv1_0))) {
        tmp8_reg_187 = grp_fu_98_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter3.read()) && esl_seteq<1,1,1>(tmp_2_reg_138_pp0_iter3_reg.read(), ap_const_lv1_0))) {
        tmp_1_reg_192 = grp_fu_98_p2.read();
    }
}

void geva_1::thread_a_address0() {
    a_address0 =  (sc_lv<6>) (zext_ln109_fu_114_p1.read());
}

void geva_1::thread_a_address1() {
    a_address1 =  (sc_lv<6>) (zext_ln109_1_fu_126_p1.read());
}

void geva_1::thread_a_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()))) {
        a_ce0 = ap_const_logic_1;
    } else {
        a_ce0 = ap_const_logic_0;
    }
}

void geva_1::thread_a_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()))) {
        a_ce1 = ap_const_logic_1;
    } else {
        a_ce1 = ap_const_logic_0;
    }
}

void geva_1::thread_add_ln105_fu_132_p2() {
    add_ln105_fu_132_p2 = (!ap_const_lv7_2.is_01() || !i_0_0_reg_86.read().is_01())? sc_lv<7>(): (sc_biguint<7>(ap_const_lv7_2) + sc_biguint<7>(i_0_0_reg_86.read()));
}

void geva_1::thread_ap_CS_fsm_pp0_stage0() {
    ap_CS_fsm_pp0_stage0 = ap_CS_fsm.read()[1];
}

void geva_1::thread_ap_CS_fsm_pp0_stage1() {
    ap_CS_fsm_pp0_stage1 = ap_CS_fsm.read()[2];
}

void geva_1::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void geva_1::thread_ap_CS_fsm_state12() {
    ap_CS_fsm_state12 = ap_CS_fsm.read()[3];
}

void geva_1::thread_ap_block_pp0_stage0() {
    ap_block_pp0_stage0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_pp0_stage0_11001() {
    ap_block_pp0_stage0_11001 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_pp0_stage0_subdone() {
    ap_block_pp0_stage0_subdone = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_pp0_stage1() {
    ap_block_pp0_stage1 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_pp0_stage1_11001() {
    ap_block_pp0_stage1_11001 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_pp0_stage1_subdone() {
    ap_block_pp0_stage1_subdone = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state10_pp0_stage0_iter4() {
    ap_block_state10_pp0_stage0_iter4 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state11_pp0_stage1_iter4() {
    ap_block_state11_pp0_stage1_iter4 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state2_pp0_stage0_iter0() {
    ap_block_state2_pp0_stage0_iter0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state3_pp0_stage1_iter0() {
    ap_block_state3_pp0_stage1_iter0 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state4_pp0_stage0_iter1() {
    ap_block_state4_pp0_stage0_iter1 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state5_pp0_stage1_iter1() {
    ap_block_state5_pp0_stage1_iter1 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state6_pp0_stage0_iter2() {
    ap_block_state6_pp0_stage0_iter2 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state7_pp0_stage1_iter2() {
    ap_block_state7_pp0_stage1_iter2 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state8_pp0_stage0_iter3() {
    ap_block_state8_pp0_stage0_iter3 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_block_state9_pp0_stage1_iter3() {
    ap_block_state9_pp0_stage1_iter3 = !esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1);
}

void geva_1::thread_ap_condition_pp0_exit_iter0_state2() {
    if (esl_seteq<1,1,1>(tmp_2_fu_102_p3.read(), ap_const_lv1_1)) {
        ap_condition_pp0_exit_iter0_state2 = ap_const_logic_1;
    } else {
        ap_condition_pp0_exit_iter0_state2 = ap_const_logic_0;
    }
}

void geva_1::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read()))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void geva_1::thread_ap_enable_pp0() {
    ap_enable_pp0 = (ap_idle_pp0.read() ^ ap_const_logic_1);
}

void geva_1::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void geva_1::thread_ap_idle_pp0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter2.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter3.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_enable_reg_pp0_iter4.read()))) {
        ap_idle_pp0 = ap_const_logic_1;
    } else {
        ap_idle_pp0 = ap_const_logic_0;
    }
}

void geva_1::thread_ap_phi_mux_i_0_0_phi_fu_90_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(tmp_2_reg_138.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0))) {
        ap_phi_mux_i_0_0_phi_fu_90_p4 = add_ln105_reg_182.read();
    } else {
        ap_phi_mux_i_0_0_phi_fu_90_p4 = i_0_0_reg_86.read();
    }
}

void geva_1::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state12.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void geva_1::thread_grp_fu_98_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read())) {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1.read(), ap_const_boolean_0))) {
            grp_fu_98_p0 = res_load_1_reg_177.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
                    esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0))) {
            grp_fu_98_p0 = res_load_reg_167.read();
        } else {
            grp_fu_98_p0 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        }
    } else {
        grp_fu_98_p0 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void geva_1::thread_grp_fu_98_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read())) {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage1.read(), ap_const_boolean_0))) {
            grp_fu_98_p1 = a_load_1_reg_172.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
                    esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0))) {
            grp_fu_98_p1 = a_load_reg_162.read();
        } else {
            grp_fu_98_p1 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        }
    } else {
        grp_fu_98_p1 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void geva_1::thread_or_ln105_fu_120_p2() {
    or_ln105_fu_120_p2 = (trunc_ln105_fu_110_p1.read() | ap_const_lv6_1);
}

void geva_1::thread_res_address0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter3.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage1.read(), ap_const_boolean_0))) {
        res_address0 = res_addr_reg_147_pp0_iter3_reg.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0))) {
        res_address0 =  (sc_lv<6>) (zext_ln109_fu_114_p1.read());
    } else {
        res_address0 =  (sc_lv<6>) ("XXXXXX");
    }
}

void geva_1::thread_res_address1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage1.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter4.read()))) {
        res_address1 = res_addr_3_reg_157_pp0_iter4_reg.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp0_stage0.read(), ap_const_boolean_0))) {
        res_address1 =  (sc_lv<6>) (zext_ln109_1_fu_126_p1.read());
    } else {
        res_address1 =  (sc_lv<6>) ("XXXXXX");
    }
}

void geva_1::thread_res_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter3.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read())))) {
        res_ce0 = ap_const_logic_1;
    } else {
        res_ce0 = ap_const_logic_0;
    }
}

void geva_1::thread_res_ce1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
          esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter4.read())))) {
        res_ce1 = ap_const_logic_1;
    } else {
        res_ce1 = ap_const_logic_0;
    }
}

void geva_1::thread_res_d0() {
    res_d0 = tmp8_reg_187.read();
}

void geva_1::thread_res_d1() {
    res_d1 = tmp_1_reg_192.read();
}

void geva_1::thread_res_we0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter3.read()) && 
         esl_seteq<1,1,1>(tmp_2_reg_138_pp0_iter3_reg.read(), ap_const_lv1_0))) {
        res_we0 = ap_const_logic_1;
    } else {
        res_we0 = ap_const_logic_0;
    }
}

void geva_1::thread_res_we1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter4.read()) && 
         esl_seteq<1,1,1>(tmp_2_reg_138_pp0_iter4_reg.read(), ap_const_lv1_0))) {
        res_we1 = ap_const_logic_1;
    } else {
        res_we1 = ap_const_logic_0;
    }
}

void geva_1::thread_tmp_2_fu_102_p3() {
    tmp_2_fu_102_p3 = ap_phi_mux_i_0_0_phi_fu_90_p4.read().range(6, 6);
}

void geva_1::thread_trunc_ln105_fu_110_p1() {
    trunc_ln105_fu_110_p1 = ap_phi_mux_i_0_0_phi_fu_90_p4.read().range(6-1, 0);
}

void geva_1::thread_zext_ln109_1_fu_126_p1() {
    zext_ln109_1_fu_126_p1 = esl_zext<64,6>(or_ln105_fu_120_p2.read());
}

void geva_1::thread_zext_ln109_fu_114_p1() {
    zext_ln109_fu_114_p1 = esl_zext<64,7>(ap_phi_mux_i_0_0_phi_fu_90_p4.read());
}

void geva_1::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_2_fu_102_p3.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(tmp_2_fu_102_p3.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter1.read(), ap_const_logic_0))) {
                ap_NS_fsm = ap_ST_fsm_state12;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter4.read()) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter3.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter4.read()) && esl_seteq<1,1,1>(ap_enable_reg_pp0_iter3.read(), ap_const_logic_0))) {
                ap_NS_fsm = ap_ST_fsm_state12;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            }
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<4>) ("XXXX");
            break;
    }
}

}

