/*
    MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:

    You may use this software, and any derivatives created by any person or
    entity by or on your behalf, exclusively with Microchip's products.
    Microchip and its subsidiaries ("Microchip"), and its licensors, retain all
    ownership and intellectual property rights in the accompanying software and
    in all derivatives hereto.

    This software and any accompanying information is for suggestion only. It
    does not modify Microchip's standard warranty for its products.  You agree
    that you are solely responsible for testing the software and determining
    its suitability.  Microchip has no obligation to modify, test, certify, or
    support the software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP'S
    PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
    (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
    INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
    ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL
    LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED
    THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF
    THESE TERMS.
*/
#include <xc.h>
#include "mtouch_sensor_scan.h"

/**
* @prototype    void MTOUCH_CVD_ScanA_0
*
* @description  CVD scanA for sensor 0
*               - name:                         Sensor_ANA4
*               - pin:                          RA4
*               - analog channel:               ANA4
*               - reference type:               MTOUCH_OPTION_REFTYPE_SELF
*               - guard type:                   NONE
*
*/
void MTOUCH_CVD_ScanA_0(void)
{
    /* Initialize Precharge Source - Sensor itself RA4 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S0_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S0_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S0_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S0_PRECHARGE_TIME);

    /* Self-Reference Logic */
    asm("movlw          113");
    asm("movwf          ADCON0 & 0x7F");
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S0_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S0_REF_PIN));
    asm("BANKSEL        ADCON0");

    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S0_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    _delay(MTOUCH_S0_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");



    /* Settling Delay */
    _delay(MTOUCH_S0_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S0_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S0_LAT) " & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_0
*
* @description    CVD scanB for sensor 0
*                - name:                         Sensor_ANA4
*                - pin:                          RA4
*                - analog channel:               ANA4
*                - reference type:               MTOUCH_OPTION_REFTYPE_SELF
*                - guard type:                   NONE
*
*/
void MTOUCH_CVD_ScanB_0(void)
{
    /* Initialize Precharge Source - Sensor itself RA4 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S0_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S0_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S0_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S0_PRECHARGE_TIME);

    /* Self-Reference Logic */
    asm("movlw          113");
    asm("movwf          ADCON0 & 0x7F");
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S0_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S0_REF_PIN));
    asm("BANKSEL        ADCON0");

    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S0_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    _delay(MTOUCH_S0_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");




    /* Settling Delay */
    _delay(MTOUCH_S0_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S0_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S0_LAT) " & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));

}

