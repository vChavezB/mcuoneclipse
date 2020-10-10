/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuWait.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : Wait
**     Version     : Component 01.087, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-10-01, 07:51, # CodeGen: 691
**     Abstract    :
**          Implements busy waiting routines.
**     Settings    :
**          Component name                                 : McuWait
**          Manual Clock Values                            : Disabled
**          Delay100usFunction                             : Delay100US
**          RTOS                                           : Enabled
**            RTOS                                         : McuRTOS
**          Watchdog                                       : Disabled
**     Contents    :
**         Wait10Cycles   - void McuWait_Wait10Cycles(void);
**         Wait100Cycles  - void McuWait_Wait100Cycles(void);
**         WaitCycles     - void McuWait_WaitCycles(uint16_t cycles);
**         WaitLongCycles - void McuWait_WaitLongCycles(uint32_t cycles);
**         Waitms         - void McuWait_Waitms(uint16_t ms);
**         Waitus         - void McuWait_Waitus(uint16_t us);
**         Waitns         - void McuWait_Waitns(uint16_t ns);
**         WaitOSms       - void McuWait_WaitOSms(void);
**         Init           - void McuWait_Init(void);
**         Deinit         - void McuWait_Deinit(void);
**
** * Copyright (c) 2013-2020, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuWait.h
** @version 01.00
** @brief
**          Implements busy waiting routines.
*/         
/*!
**  @addtogroup McuWait_module McuWait module documentation
**  @{
*/         

/* MODULE McuWait. */

#include "McuWait.h"


/*
** ===================================================================
**     Method      :  Wait10Cycles (component Wait)
**
**     Description :
**         Wait for 10 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#ifdef __GNUC__
#if McuLib_CONFIG_CPU_IS_RISC_V /* naked is ignored for RISC-V gcc */
  #ifdef __cplusplus  /* gcc 4.7.3 in C++ mode does not like no_instrument_function: error: can't set 'no_instrument_function' attribute after definition */
  #else
    __attribute__((no_instrument_function))
  #endif
#else
  #ifdef __cplusplus  /* gcc 4.7.3 in C++ mode does not like no_instrument_function: error: can't set 'no_instrument_function' attribute after definition */
    __attribute__((naked))
  #else
    __attribute__((naked, no_instrument_function))
  #endif
#endif
#endif
void McuWait_Wait10Cycles(void)
{
  /* This function will wait 10 CPU cycles (including call overhead). */
  /*lint -save -e522 function lacks side effect. */

#if McuLib_CONFIG_CPU_IS_ARM_CORTEX_M
  /* NOTE: Cortex-M0 and M4 have 1 cycle for a NOP */
#if McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_GNU
  __asm (
   /* bl Wait10Cycles() to here: [4] */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
   "bx lr \n\t" /* [3] */
  );
#elif McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_IAR
  /* bl Wai10Cycles() to here: [4] */
  __asm("nop");   /* [1] */
  __asm("nop");   /* [1] */
  __asm("nop");   /* [1] */
  __asm("bx lr"); /* [3] */
#elif McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_KEIL
  __asm {
    nop                                      /* [1] */
    nop                                      /* [1] */
    nop                                      /* [1] */
    /*bx lr*/                                /* [3] */
  }
#else
  __asm {
    nop                                      /* [1] */
    nop                                      /* [1] */
    nop                                      /* [1] */
    bx lr                                    /* [3] */
  }
#endif
#elif McuLib_CONFIG_CPU_IS_RISC_V
  /* \todo */
  __asm ( /* assuming [4] for overhead */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
   "nop   \n\t" /* [1] */
  );
#endif
  /*lint -restore */
}

/*
** ===================================================================
**     Method      :  Wait100Cycles (component Wait)
**
**     Description :
**         Wait for 100 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#if McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_IAR
  /* Implemented in assembly file, as IAR does not support labels in HLI */
#else
#ifdef __GNUC__
  #if McuLib_CONFIG_CPU_IS_RISC_V /* naked is ignored for RISC-V gcc */
    #ifdef __cplusplus  /* gcc 4.7.3 in C++ mode does not like no_instrument_function: error: can't set 'no_instrument_function' attribute after definition */
    #else
      __attribute__((no_instrument_function))
    #endif
  #else
    #ifdef __cplusplus  /* gcc 4.7.3 in C++ mode does not like no_instrument_function: error: can't set 'no_instrument_function' attribute after definition */
      __attribute__((naked))
    #else
      __attribute__((naked, no_instrument_function))
    #endif
  #endif
#endif
void McuWait_Wait100Cycles(void)
{
  /* This function will spend 100 CPU cycles (including call overhead). */
  /*lint -save -e522 function lacks side effect. */
#if McuLib_CONFIG_CPU_IS_ARM_CORTEX_M
#if McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_GNU
  __asm (
   /* bl to here:               [4] */
   "push {r0}   \n\t"        /* [2] */
   "movs r0, #0 \n\t"        /* [1] */
   "loopWait100Cycles:       \n\t"
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "add r0,#1   \n\t"        /* [1] */
   "cmp r0,#9   \n\t"        /* [1] */
   "bls loopWait100Cycles    \n\t"        /* [3] taken, [1] not taken */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "nop         \n\t"        /* [1] */
   "pop {r0}    \n\t"        /* [2] */
   "bx lr       \n\t"        /* [3] */
  );
#elif McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_IAR
  /* need to implement in assembly, as IAR does not support labels in HLI */
#elif McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_KEIL
   /* bl to here:    [4] */
    movs r0, #0   /* [1] */
loop
    nop           /* [1] */
    nop           /* [1] */
    nop           /* [1] */
    nop           /* [1] */
    nop           /* [1] */
    adds r0,r0,#1 /* [1] */
    cmp r0,#9     /* [1] */
    bls loop      /* [3] taken, [1] not taken */
    nop           /* [1] */
    bx lr         /* [3] */
#else
  __asm {
   /* bl Wai10Cycles() to here: [4] */
    movs r0, #0 /* [1] */
   loop:
    nop         /* [1] */
    nop         /* [1] */
    nop         /* [1] */
    nop         /* [1] */
    nop         /* [1] */
    add r0,#1   /* [1] */
    cmp r0,#9   /* [1] */
    bls loop    /* [3] taken, [1] not taken */
    nop         /* [1] */
    bx lr       /* [3] */
  }
#endif
#elif McuLib_CONFIG_CPU_IS_RISC_V
  /* \todo */
  __asm ( /* assuming [10] for overhead */
    "  li a5,20        \n\t"
    "LoopWait100Cycles:             \n\t"
    "  addi a5,a5,-1   \n\t"
    "  bgtz a5, LoopWait100Cycles   \n\t"
  );
#endif
  /*lint -restore */
}
#endif  /* McuLib_CONFIG_COMPILER==McuLib_CONFIG_COMPILER_IAR */

/*
** ===================================================================
**     Method      :  WaitCycles (component Wait)
**
**     Description :
**         Wait for a specified number of CPU cycles (16bit data type).
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/
void McuWait_WaitCycles(uint16_t cycles)
{
  /*lint -save -e522 function lacks side effect. */
#if McuWait_CONFIG_USE_CYCLE_COUNTER
  uint32_t counter = cycles;

  counter += McuArmTools_GetCycleCounter();
  while(McuArmTools_GetCycleCounter()<counter) {
    /* wait */
  }
#else
  while(cycles >= 100u) {
    McuWait_Wait100Cycles();
    cycles -= 100u;
  }
  while(cycles >= 10u) {
    McuWait_Wait10Cycles();
    cycles -= 10u;
  }
#endif
  /*lint -restore */
}

/*
** ===================================================================
**     Method      :  WaitLongCycles (component Wait)
**
**     Description :
**         Wait for a specified number of CPU cycles (32bit data type).
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/
void McuWait_WaitLongCycles(uint32_t cycles)
{
#if McuWait_CONFIG_USE_CYCLE_COUNTER
  uint32_t counter = cycles;

  counter += McuArmTools_GetCycleCounter();
  while(McuArmTools_GetCycleCounter()<counter) {
    /* wait */
  }
#else
  /*lint -save -e522 function lacks side effect. */
  while(cycles>60000) {
    McuWait_WaitCycles(60000);
    cycles -= 60000;
  }
  McuWait_WaitCycles((uint16_t)cycles);
  /*lint -restore */
#endif
}

/*
** ===================================================================
**     Method      :  Waitms (component Wait)
**
**     Description :
**         Wait for a specified time in milliseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ms              - How many milliseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/
void McuWait_Waitms(uint16_t ms)
{
  /*lint -save -e522 function lacks side effect. */
  uint32_t msCycles; /* cycles for 1 ms */

  /* static clock/speed configuration */
  msCycles = McuWait_NofCyclesMs(1, McuWait_INSTR_CLOCK_HZ);
  while(ms>0) {
    McuWait_WaitLongCycles(msCycles);
    ms--;
  }
  /*lint -restore */
}
/*
** ===================================================================
**     Method      :  Waitus (component Wait)
**
**     Description :
**         Wait for a specified time in microseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - How many microseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/
/* implemented as macro version. See header file. */
/*
** ===================================================================
**     Method      :  Waitns (component Wait)
**
**     Description :
**         Wait for a specified time in nano seconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ns              - How many ns the function has to wait
**     Returns     : Nothing
** ===================================================================
*/
/* implemented as macro version. See header file. */
/*
** ===================================================================
**     Method      :  WaitOSms (component Wait)
**
**     Description :
**         If an RTOS is enabled, this routine will use a non-blocking
**         wait method. Otherwise it will do a busy/blocking wait.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void McuWait_WaitOSms(void)
{
  Method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  Init (component Wait)
**
**     Description :
**         Driver initialization routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuWait_Init(void)
{
#if McuWait_CONFIG_USE_CYCLE_COUNTER
  /* init cycle counter */
  McuArmTools_InitCycleCounter();
  McuArmTools_ResetCycleCounter();
  McuArmTools_EnableCycleCounter();
#endif
}

/*
** ===================================================================
**     Method      :  Deinit (component Wait)
**
**     Description :
**         Driver de-initialization routine
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuWait_Deinit(void)
{
#if McuWait_CONFIG_USE_CYCLE_COUNTER
  /* disable hardware cycle counter */
  McuArmTools_DisableCycleCounter();
#endif
}

/* END McuWait. */

/*!
** @}
*/
