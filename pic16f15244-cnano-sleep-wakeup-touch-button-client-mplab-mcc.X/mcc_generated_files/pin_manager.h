/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F15244
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED6 aliases
#define LED6_TRIS                 TRISAbits.TRISA5
#define LED6_LAT                  LATAbits.LATA5
#define LED6_PORT                 PORTAbits.RA5
#define LED6_WPU                  WPUAbits.WPUA5
#define LED6_OD                   ODCONAbits.ODCA5
#define LED6_ANS                  ANSELAbits.ANSA5
#define LED6_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED6_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED6_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED6_GetValue()           PORTAbits.RA5
#define LED6_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED6_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED6_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED6_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED6_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED6_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED6_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED6_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set OUT_PIN aliases
#define OUT_PIN_TRIS                 TRISCbits.TRISC3
#define OUT_PIN_LAT                  LATCbits.LATC3
#define OUT_PIN_PORT                 PORTCbits.RC3
#define OUT_PIN_WPU                  WPUCbits.WPUC3
#define OUT_PIN_OD                   ODCONCbits.ODCC3
#define OUT_PIN_ANS                  ANSELCbits.ANSC3
#define OUT_PIN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define OUT_PIN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define OUT_PIN_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define OUT_PIN_GetValue()           PORTCbits.RC3
#define OUT_PIN_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define OUT_PIN_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define OUT_PIN_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define OUT_PIN_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define OUT_PIN_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define OUT_PIN_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define OUT_PIN_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define OUT_PIN_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/