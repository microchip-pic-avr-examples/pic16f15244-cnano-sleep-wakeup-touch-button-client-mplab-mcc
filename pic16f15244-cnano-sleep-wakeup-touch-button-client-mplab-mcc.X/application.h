/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>                                                              // Include processor files - each processor file is guarded.  
#include "mcc_generated_files/mcc.h"

/*
 ***********************************************************
 *                                                         *
 *              USER DEFINED MACROS                        *
 *                                                         *
 ***********************************************************
*/

#define BIT_SET             (1)
#define BIT_RESET           (0)
#define BIT_ENABLE          (1)
#define BIT_DISABLE         (0)
#define ONE_HOUR            (1)
#define HOLD_TIME           (20)
#define ONE_HR_PERIOD       (750)                        // Multiplying factor for 1hr considering the 20ms interrupt

/* 
 *      USER DEFINED FUNCTIONS
 */
extern uint8_t sleep_flag;
extern uint32_t periodic_wakeup_count;
extern uint8_t timer_flag;

/**
   @Param
    enumerated data of button pressed
   @Returns
    none
   @Description
    Sets up the functionality when the touch button is pressed
   @Example
    none
 */
void ProcessButtonTouch(enum mtouch_button_names button);

/**
   @Param
    enumerated data of button released
   @Returns
    none
   @Description
    Sets up the functionality when the touch button is released
   @Example
    none
 */
void ProcessButtonRelease(enum mtouch_button_names button);

/**
   @Param
    none
   @Returns
    none
   @Description
    Performs functionality of sending the interrupt signal to host device as and when the conditions are matched or touch button is pressed
   @Example
    none
 */
void Application(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Toggles the RB5 pin for sending the interrupt signal to host device
   @Example
    none
 */
void PinToggle(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Increments the system reset flag when the 15 seconds period is completed, used for periodic interrupt to the host device
   @Example
    none
 */
void TMR2_UserInterruptHandler(void);

#endif	/* XC_HEADER_TEMPLATE_H */

