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
#ifndef MTOUCH_RANDOM_H
#define MTOUCH_RANDOM_H

    #define MTOUCH_RANDOM_BIT   8

    /*
     *  Generates a pseudo-random value based on the Galois LFSR algorithm.
     *
     *  If MTOUCH_RANDOM_BIT is 8, then an 8-bit value is used for the seed and
     *  the output of the function will repeat after 2^8 function calls.
     *
     *  If MTOUCH_RANDOM_BIT is 16, then a 16-bit value is used for the seed and
     *  the output of the function will repeat after 2^16 function calls.
     *
     *  If MTOUCH_RANDOM_BIT is 24, then a 24-bit value is used for the seed and
     *  the output of the function will repeat after 2^24 function calls.
     *
     *  If MTOUCH_RANDOM_BIT is 32, then a 32-bit value is used for the seed and
     *  the output of the function will repeat after 2^32 function calls.
     *
     *  @prototype      uint8_t MTOUCH_Random(void)
     *
     *  @return         a pseudo-random value. NOT SUFFICIENT FOR ANY ALGORITHM
     *                  NEEDING TRUE RANDOMIZATION such as cryptography. Plenty
     *                  of randomness to implement mTouch sample rate jittering.
     */
    uint8_t MTOUCH_Random(void);
    
#endif
