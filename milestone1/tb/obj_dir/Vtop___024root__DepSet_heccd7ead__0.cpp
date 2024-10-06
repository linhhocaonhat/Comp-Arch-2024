// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

extern const VlUnpacked<CData/*0:0*/, 16> Vtop__ConstPool__TABLE_ha627eeae_0;
extern const VlUnpacked<CData/*2:0*/, 16> Vtop__ConstPool__TABLE_ha83ef25c_0;

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx2;
    // Body
    vlSelf->top__DOT__vending__DOT__current_state = 
        ((IData)(vlSelf->i_rst) ? (IData)(vlSelf->top__DOT__vending__DOT__next_state)
          : 0U);
    __Vtableidx2 = vlSelf->top__DOT__vending__DOT__current_state;
    vlSelf->o_soda = Vtop__ConstPool__TABLE_ha627eeae_0
        [__Vtableidx2];
    vlSelf->o_change = Vtop__ConstPool__TABLE_ha83ef25c_0
        [__Vtableidx2];
}

extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h0e7a29f3_0;

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->i_quarter) << 6U) 
                    | (((IData)(vlSelf->i_dime) << 5U) 
                       | (((IData)(vlSelf->i_nickel) 
                           << 4U) | (IData)(vlSelf->top__DOT__vending__DOT__current_state))));
    vlSelf->top__DOT__vending__DOT__next_state = Vtop__ConstPool__TABLE_h0e7a29f3_0
        [__Vtableidx1];
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->i_clk) & (~ (IData)(vlSelf->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlSelf->i_rst)) & (IData)(vlSelf->__Vclklast__TOP__i_rst)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    Vtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__i_clk = vlSelf->i_clk;
    vlSelf->__Vclklast__TOP__i_rst = vlSelf->i_rst;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((vlSelf->i_rst & 0xfeU))) {
        Verilated::overWidthError("i_rst");}
    if (VL_UNLIKELY((vlSelf->i_nickel & 0xfeU))) {
        Verilated::overWidthError("i_nickel");}
    if (VL_UNLIKELY((vlSelf->i_dime & 0xfeU))) {
        Verilated::overWidthError("i_dime");}
    if (VL_UNLIKELY((vlSelf->i_quarter & 0xfeU))) {
        Verilated::overWidthError("i_quarter");}
}
#endif  // VL_DEBUG
