/**
 * Main driver
 *
 * Author:  Zach Tucker
 * Version: 11052019
 */

#include <stdio.h>
#include <stdlib.h>
#include "memset.h"

int main(int argc, char **argv) {
   
    int c = 0x20;
    int size = strtol(argv[1], NULL, 10); 
    int s[size], *r;

    r = (int*) first_memset(s, c, size);
}
