// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtidc_system_tb.h for the primary calling header

#ifndef _VTIDC_SYSTEM_TB___024UNIT_H_
#define _VTIDC_SYSTEM_TB___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtidc_system_tb__Syms;
class Vtidc_system_tb_VerilatedVcd;


//----------

VL_MODULE(Vtidc_system_tb___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vtidc_system_tb__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtidc_system_tb___024unit);  ///< Copying not allowed
  public:
    Vtidc_system_tb___024unit(const char* name = "TOP");
    ~Vtidc_system_tb___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vtidc_system_tb__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
