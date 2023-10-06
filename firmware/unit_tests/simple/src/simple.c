#include <stdio.h>
#include "library.h"

/*
  Increment a number infinitely. 
  
  Used to verify that a QEMU machine can run firmware
*/

void main(void){
        
    uint8_t add = 0;
    
    while (1){
        add++;             
    }
}

