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

/*----------------------------------------------------------------------------
  include files
----------------------------------------------------------------------------*/
#include "mtouch_datastreamer.h"
#include "../mcc.h"

#if (MTOUCH_DEBUG_COMM_ENABLE == 1u)
/*----------------------------------------------------------------------------
  manifest constants
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  global variables
----------------------------------------------------------------------------*/
uint8_t data[] = {0x5F,
    0xB4, 0x00, 0x86, 0x4A,
    0x03, 0xEB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0x55, 0x01,
    0x6E,
    0xA0};

/*----------------------------------------------------------------------------
  prototypes
----------------------------------------------------------------------------*/
void MTOUCH_DataStreamer_Initialize(void)
{
}

void inline datastreamer_output_byte(uint8_t data) 
{
    EUSART1_Write(data);
}

void MTOUCH_DataStreamer_Service(void) 
{
    uint8_t i;
    static uint8_t sequence = 0u;
    uint16_t u16temp_output;
    uint8_t u8temp_output;
    volatile uint8_t count_bytes_out;

    if ((sequence % 10) == 0) 
    {
        for (i = 0; i < sizeof (data); i++)
            datastreamer_output_byte(data[i]);
    }

    // Start token
    datastreamer_output_byte(0x55);

    datastreamer_output_byte(sequence);

    /* table - button specific data */
    for (count_bytes_out = 0u; count_bytes_out < MTOUCH_BUTTONS; count_bytes_out++) 
    {
        u16temp_output = MTOUCH_Button_Reading_Get(count_bytes_out);
        datastreamer_output_byte((uint8_t) u16temp_output);
        datastreamer_output_byte((uint8_t) (u16temp_output >> 8u));

        u16temp_output = MTOUCH_Button_Baseline_Get(count_bytes_out);
        datastreamer_output_byte((uint8_t) u16temp_output);
        datastreamer_output_byte((uint8_t) (u16temp_output >> 8u));

        u16temp_output = (uint16_t)((int16_t)MTOUCH_Button_Deviation_Get(count_bytes_out));
        datastreamer_output_byte((uint8_t) u16temp_output);
        datastreamer_output_byte((uint8_t) (u16temp_output >> 8u));

        u16temp_output = MTOUCH_Button_Scaling_Get(count_bytes_out);
        datastreamer_output_byte((uint8_t) u16temp_output);
        datastreamer_output_byte((uint8_t) (u16temp_output >> 8u));

        datastreamer_output_byte(MTOUCH_Button_Threshold_Get(count_bytes_out));

        datastreamer_output_byte(MTOUCH_Button_isPressed(count_bytes_out));

    }

    
    
    
    datastreamer_output_byte(sequence++);

    // End token
    datastreamer_output_byte(~0x55);
}

#endif
