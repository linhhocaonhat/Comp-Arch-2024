// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h0e7a29f3_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtop__ConstPool__TABLE_ha627eeae_0;
extern const VlUnpacked<CData/*2:0*/, 16> Vtop__ConstPool__TABLE_ha83ef25c_0;

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    CData/*3:0*/ __Vtableidx2;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->i_quarter) << 6U) 
                    | (((IData)(vlSelf->i_dime) << 5U) 
                       | (((IData)(vlSelf->i_nickel) 
                           << 4U) | (IData)(vlSelf->top__DOT__vending__DOT__current_state))));
    vlSelf->top__DOT__vending__DOT__next_state = Vtop__ConstPool__TABLE_h0e7a29f3_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelf->top__DOT__vending__DOT__current_state;
    vlSelf->o_soda = Vtop__ConstPool__TABLE_ha627eeae_0
        [__Vtableidx2];
    vlSelf->o_change = Vtop__ConstPool__TABLE_ha83ef25c_0
        [__Vtableidx2];
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
    vlSelf->__Vclklast__TOP__i_rst = vlSelf->i_rst;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_clk = VL_RAND_RESET_I(1);
    vlSelf->i_rst = VL_RAND_RESET_I(1);
    vlSelf->i_nickel = VL_RAND_RESET_I(1);
    vlSelf->i_dime = VL_RAND_RESET_I(1);
    vlSelf->i_quarter = VL_RAND_RESET_I(1);
    vlSelf->o_soda = VL_RAND_RESET_I(1);
    vlSelf->o_change = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__vending__DOT__current_state = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__vending__DOT__next_state = VL_RAND_RESET_I(4);
}
