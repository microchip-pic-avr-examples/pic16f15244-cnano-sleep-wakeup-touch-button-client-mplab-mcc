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
#include <stdint.h>
#include "mtouch_random.h"

    #if     MTOUCH_RANDOM_BIT == 8
    
        /* Do not edit these values. */
        #define MTOUCH_RANDOM_XOR   0xB4
        typedef uint8_t MTOUCH_RANDOM_t;
        
    #elif   MTOUCH_RANDOM_BIT == 16

        /* Do not edit these values. */
        #define MTOUCH_RANDOM_XOR   0xA1A1
        typedef uint16_t MTOUCH_RANDOM_t;
        
    #elif   MTOUCH_RANDOM_BIT == 24

        /* Do not edit these values. */
        #define MTOUCH_RANDOM_XOR   0xD7D7D7
        typedef uint_least24_t MTOUCH_RANDOM_t;
        
    #elif   MTOUCH_RANDOM_BIT == 32

        /* Do not edit these values. */
        #define MTOUCH_RANDOM_XOR   0xA6A6A6A6
        typedef uint32_t MTOUCH_RANDOM_t;
        
    #endif

uint8_t MTOUCH_Random(void)
{
    static MTOUCH_RANDOM_t seed = (MTOUCH_RANDOM_t)0;

    if ((seed & (MTOUCH_RANDOM_t)1) != (MTOUCH_RANDOM_t)0)
    {
        /* If the LSb of "seed" is a '1' then divide seed by 2. */
        seed = seed >> (uint8_t)1;
    }
    else
    {
        /*
         * If the LSb of "seed" is a '0' then divide seed by 2, and XOR it with
         * the LFSR polynom.
         */
        seed = seed >> (uint8_t)1;
        seed = seed ^ (MTOUCH_RANDOM_t)MTOUCH_RANDOM_XOR;
    }

    return (uint8_t)seed & 0x0F;
}
