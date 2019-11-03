#include <unistd.h>

/**
 * Attempts to optimize an implementation of memset.
 *
 * Author: Zach Tucker
 * Version 11032019
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


