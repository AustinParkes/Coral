#include <stdio.h>
#include "library.h"

/*
 *  Test coral's general callback functionality to ensure callbacks
 *  are called as expected:
 *  1) Mapped callbacks
 *  2) Unmapped callbacks
 *  3) Status Register Bypass callbacks
 *  
 *  Test with 8, 16, 32, and 64 bit register sizes using preprocessor 
 *  definitions below.
 *
 *  Configuration File: test_callbacks.toml 
*/

#define TEST_8_BIT  1
#define TEST_16_BIT  0
#define TEST_32_BIT  0
#define TEST_64_BIT  0

void test_callbacks(void);

void main(void){

  test_callbacks();  
      
}

void test_callbacks()
{
#if TEST_8_BIT
    volatile uint8_t * const mapped_reg = (uint8_t *)0x40000000;
    volatile uint8_t * const unmapped_reg = (uint8_t *)0x50000000;
#elif TEST_16_BIT    
    volatile uint16_t * const mapped_reg = (uint16_t *)0x40000000;
    volatile uint16_t * const unmapped_reg = (uint16_t *)0x50000000;
#elif TEST_32_BIT    
    volatile uint32_t * const mapped_reg = (uint32_t *)0x40000000;
    volatile uint32_t * const unmapped_reg = (uint32_t *)0x50000000;
#elif TEST_64_BIT    
    volatile uint64_t * const mapped_reg = (uint64_t *)0x40000000;
    volatile uint64_t * const unmapped_reg = (uint64_t *)0x50000000;         
#endif    
    
    uint64_t read;   
    
    /*
     * Test callback for registered mmio
     * Write to a mapped register
     * Read a mapped register
     */
    *mapped_reg = 1;
    read = *mapped_reg;    
                
     /*
      * Test callback for non-registered mmio
      * Write to an unmapped register
      * Read an unmapped register
      */
    *unmapped_reg = 1;
    read = *unmapped_reg;
    
    /*
     * TODO: Test callback for a status register bypass
     * Read from a status register.
     * Write to mapped register upon success.
     */   
}


