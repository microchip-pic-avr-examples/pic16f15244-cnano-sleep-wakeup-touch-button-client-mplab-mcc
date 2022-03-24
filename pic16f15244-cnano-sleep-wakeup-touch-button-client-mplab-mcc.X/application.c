/*
 * File:   application.c
 * Author: I62418
 *
 * Created on August 2, 2021, 10:42 AM
 */


#include <xc.h>
#include "application.h"
#include "mcc_generated_files/mcc.h"

/*
 ***********************************************************
 *                                                         *
 *              USER DEFINED VARIABLES                     *
 *                                                         *
 ***********************************************************
*/

uint8_t userInput, receive_flag;
uint32_t systemResetPeriod;
uint8_t activeStateFlag, touchEventFlag;
/*
 ***********************************************************
 *                                                         *
 *              FUNCTION DEFINITIONS                       *
 *                                                         *
 ***********************************************************
*/

void ProcessButtonTouch(enum mtouch_button_names button)
{
    switch(button)
    {
        case Button0:
            LED6_SetLow();                             // Visual indication of touch button being pressed
            touchEventFlag = BIT_SET;
            break;
        
        default:
            break;
    }
}
 
void ProcessButtonRelease(enum mtouch_button_names button)
{
    switch(button)
    {
        case Button0:                                  // Button0 is selected as input in mTouch library
            LED6_SetHigh();                            // Visual indication of button being released            
            if(touchEventFlag == BIT_SET)
            {
                touchEventFlag = BIT_RESET;
                activeStateFlag = BIT_SET;
            }
            break;
        
        default:
            break;
    }
}

void Application(void)
{
     if(eusart1RxCount!=0)                             // Monitor if host device has sent the periodic time signal
    {        
        userInput = EUSART1_Read();
        receive_flag = BIT_SET;
        systemResetPeriod = (userInput * ONE_HR_PERIOD);
    }

    if((receive_flag == BIT_SET) && (periodic_wakeup_count > ONE_HR_PERIOD))
    {
        periodic_wakeup_count = BIT_RESET;             // Reset the system reset flag
        PinToggle();                                   // Send high pulse to host device as an interrupt signal
        sleep_flag = BIT_SET;
    }
    if(activeStateFlag == BIT_SET)                    // Perform activity only if the button is pressed else go to sleep mode
    {
        activeStateFlag = BIT_RESET;
        PinToggle();
        sleep_flag = BIT_SET;
    }
    if(sleep_flag == BIT_SET)                          // Check if MCU is idle. If yes, enable sleep mode
    {
        sleep_flag = BIT_RESET;
        SLEEP();
    }
}

void PinToggle(void)
{
    OUT_PIN_SetHigh();                                 // Set the pin for sending pulse signal for waking the host device
    __delay_ms(HOLD_TIME);
    OUT_PIN_SetLow();                                  // Reset the pin
}
