/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuEvents.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : SimpleEvents
**     Version     : Component 01.058, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-04-15, 12:58, # CodeGen: 596
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuEvents
**          SDK                                            : McuLib
**          Critical Section                               : McuCriticalSection
**          Initialize on Init                             : yes
**          Event Name List                                : (string list)
**     Contents    :
**         SetEvent      - void McuEvents_SetEvent(uint8_t event);
**         ClearEvent    - void McuEvents_ClearEvent(uint8_t event);
**         EventsPending - bool McuEvents_EventsPending(void);
**         GetEvent      - bool McuEvents_GetEvent(uint8_t event);
**         GetClearEvent - bool McuEvents_GetClearEvent(uint8_t event);
**         HandleEvent   - void McuEvents_HandleEvent(void);
**
** * Copyright (c) 2011-2019, Erich Styger
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
** @file McuEvents.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuEvents_module McuEvents module documentation
**  @{
*/         

/* MODULE McuEvents. */
#include "McuEvents.h"

#include "McuCriticalSection.h"


static uint8_t McuEvents_Events[((McuEvents_CONFIG_NOF_EVENTS-1)/8)+1]; /*!< Bit set of events */
/*
** ===================================================================
**     Method      :  SetEvent (component SimpleEvents)
**
**     Description :
**         Sets an event (number) be processed by the next HandleEvent()
**         call
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event (number) to be set so it
**                           will be called by the HandleEvent() routine
**                           later on. Note that there cannot be
**                           multiple instances of an event, and the
**                           lower the event number, the higher the
**                           priority.
**     Returns     : Nothing
** ===================================================================
*/
void McuEvents_SetEvent(uint8_t event)
{
  McuCriticalSection_CriticalVariable();

  /* event is in the range of 0..255: find bit position in array */
  McuCriticalSection_EnterCritical();
  McuEvents_Events[event/8] |= 0x80>>(event%8);
  McuCriticalSection_ExitCritical();
}

/*
** ===================================================================
**     Method      :  ClearEvent (component SimpleEvents)
**
**     Description :
**         Clears one event (number). If the event is not set, then the
**         function has no effect.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event number to be cleared.
**     Returns     : Nothing
** ===================================================================
*/
void McuEvents_ClearEvent(uint8_t event)
{
  McuCriticalSection_CriticalVariable();

 /* event is in the range of 0..255: find bit position in array */
  McuCriticalSection_EnterCritical();
  McuEvents_Events[event/8] &= ~(0x80>>(event%8));
  McuCriticalSection_ExitCritical();
}

/*
** ===================================================================
**     Method      :  GetEvent (component SimpleEvents)
**
**     Description :
**         Allows to check if an event is set or not.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event number to check. If the
**                           event is set, the function returns TRUE.
**     Returns     :
**         ---             - none
** ===================================================================
*/
bool McuEvents_GetEvent(uint8_t event)
{
  /* event is in the range of 0..255: find bit position in array */
  return (bool)((McuEvents_Events[event/8]&(0x80>>(event%8)))!=0);
}

/*
** ===================================================================
**     Method      :  GetClearEvent (component SimpleEvents)
**
**     Description :
**         Allows to check if an event is set or not. If set, it will
**         be automatically cleared.
**     Parameters  :
**         NAME            - DESCRIPTION
**         event           - The event number to check. If the
**                           event is set, the function returns TRUE.
**     Returns     :
**         ---             - none
** ===================================================================
*/
bool McuEvents_GetClearEvent(uint8_t event)
{
  bool isSet = FALSE;
  McuCriticalSection_CriticalVariable();

  McuCriticalSection_EnterCritical();
  if (McuEvents_GetEvent(event)) { /* event present */
    McuEvents_Events[event/8] &= ~(0x80>>(event%8)); /* clear event */
    isSet = TRUE;
  }
  McuCriticalSection_ExitCritical();
  return isSet;
}

/*
** ===================================================================
**     Method      :  EventsPending (component SimpleEvents)
**
**     Description :
**         Returns true if any events are pending, false otherwise
**     Parameters  : None
**     Returns     :
**         ---             - True in case any events are pending, false
**                           otherwise.
** ===================================================================
*/
bool McuEvents_EventsPending(void)
{
#if McuEvents_CONFIG_NOF_EVENTS<=8
  return (bool)(McuEvents_Events[0]!=0);
#elif McuEvents_CONFIG_NOF_EVENTS<=16
  return (bool)(McuEvents_Events[0]!=0 || McuEvents_Events[1]!=0);
#elif McuEvents_CONFIG_NOF_EVENTS<=24
  return (McuEvents_Events[0]!=0 || McuEvents_Events[1]!=0 || McuEvents_Events[2]!=0);
#elif McuEvents_CONFIG_NOF_EVENTS<=32
  return (bool)(McuEvents_Events[0]!=0 || McuEvents_Events[1]!=0 || McuEvents_Events[2]!=0 || McuEvents_Events[3]!=0);
#else /* iterate through the array */
  char i; /* local counter */

  for(i=0; i<(McuEvents_CONFIG_NOF_EVENTS/8)+1; i++) {
    if (McuEvents_Events[i] != 0) { /* there are events pending */
      return TRUE;
    }
  }
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  HandleEvent (component SimpleEvents)
**
**     Description :
**         Event handler, to be called periodically.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuEvents_HandleEvent(void)
{
  /* Handle the one with the highest priority. */
  uint8_t event;
  McuCriticalSection_CriticalVariable();

  McuCriticalSection_EnterCritical();
  for (event=0; event<McuEvents_CONFIG_NOF_EVENTS; event++) { /* does a test on every event */
    if (McuEvents_GetEvent(event)) { /* event present */
      McuEvents_Events[event/8] &= ~(0x80>>(event%8)); /* clear event */
      break; /* get out of loop */
    }
  }
  McuCriticalSection_ExitCritical();
#if McuEvents_CONFIG_USE_EVENT_HANDLER
  /*lint -save -e522 function lacks side effect  */
  if (event != McuEvents_CONFIG_NOF_EVENTS) {
    McuEvents_CONFIG_EVENT_HANDLER_NAME(event);
  }
  /*lint -restore */
#endif
}

/*
** ===================================================================
**     Method      :  McuEvents_Init (component SimpleEvents)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void McuEvents_Init(void)
{
#if McuEvents_CONFIG_NOF_EVENTS<=8
  McuEvents_Events[0] = 0; /* initialize data structure */
#else
  uint8_t i;

  for(i=0;i<sizeof(McuEvents_Events); i++) {
    McuEvents_Events[i] = 0; /* initialize data structure */
  }
#endif
}

/* END McuEvents. */

/*!
** @}
*/
