/**
 * Attempts to optimize prefix-sum computation
 *
 * Author: Zach Tucker & Ryan Showalter
 * Version: 11142019
 */

/* Compute prefix sum of a vector a */
void psum1(float a[], float p[], long n) {
    
    long i;
    p[0] = a[0];
    for (i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i];
    }
}

/* Compute prefix sum of a vector a */
void psum2(float a[], float p[], long n) {
    
    long i;
    p[0] = a[0];
    for (i = 1; i < n - 1; i+= 2) {
        float mid_val = p[i - 1] + a[i];
        p[i]     = mid_val;
        p[i + 1] = mid_val;
    }

    /* For even n, finish remaining element */
    if (i < n) {
        p[i] = p[i - 1] + a[i];
    }
}

/* Compute prefix sum of a vector a */
void psum1a(float a[], float p[], long n) {
    
    long i;

    /* last_val holds p[i-1]; val holds p[i] */
    float last_val, val;
    last_val = p[0] = a[0];
    for (i = 1; i < n; i++) {
        val = last_val + a[i];
        p[i] = val;
        last_val = val;
    }
}   
