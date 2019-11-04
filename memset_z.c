#include <unistd.h>
#include <inttypes.h>

/**
 * Attempts to optimize an implementation of memset.
 *
 * Author: Zach Tucker
 * Version 11042019
 */

/* Basic implementation of memset */
void *basic_memset(void *s, int c, size_t n) {
    
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }
    return s;
}

/* Implementation of memset that sets memory in groups of 8 bytes */
void* memset(void *s, int c, size_t n) {

    size_t cnt = 0;
    unsigned char *schar = s;
    uint64_t chars;
    uint8_t *temp = (uint8_t*) s;
    
    // Place c in chars
    for (int i = 0; i < 8; i++) {
        temp[i] = c;
    }

    // set memory in groups of 8 bytes
    while (cnt + 8 < n) {
        *schar = (unsigned char) chars;
        schar += 8;
        cnt += 8;
    }
    
    // Do the rest of memory
    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }   

    return s;
}
