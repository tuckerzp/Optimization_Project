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
        p[i + 1] = mid_val + a[i + 1];
    }

    /* For even n, finish remaining element */
    if (i < n) {
        p[i] = p[i - 1] + a[i];
    }
}

void psum4(float a[], float p[], long n) {
    
    long i;
    p[0] = a[0];

    for (i = 1; i < n - 3; i += 4) {
        float first_mid = p[i - 1] + a[i];
        float val;
        
        p[i] = first_mid;
        val = first_mid + a[i + 1];
        p[i + 1] = val;

        float second_mid = val + a[i + 2];

        p[i + 2] = second_mid;
        val = second_mid + a[i + 3];
        p[i + 3] = val;
    }

    for (; i < n; i++) {
        p[i] = p[i - 1] + a[i];
    }
}

void psum4_b(float a[], float p[], long n) {
    long i;
    float last_val = p[0] = a[0];

    float a0, a1, a2, a3;
    float tmp0, tmp1, tmp2, tmp3;

    for (i = 1; i < n - 3; i += 4) {
        
        a0 = a[i];
        a1 = a[i + 1];
        a2 = a[i + 2];
        a3 = a[i + 3];

        tmp0 = last_val + a0;
        tmp1 = tmp0 + a1;
        tmp2 = tmp1 + a2;
        tmp3 = tmp2 + a3;

        p[i] = tmp0;
        p[i + 1] = tmp1;
        p[i + 2] = tmp2;
        p[i + 3] = tmp3;

        last_val += (a0 + a1) + (a2 + a3);
    }

    for (; i < n; i++) {
        tmp0 = last_val + a[i];
        p[i] = tmp0;
        last_val = tmp0;
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

void psum2a(float a[], float p[], long n) {
    
    long i;

    /* last_val holds p[i - 1]; val holds p[i + 1] */
    float last_val, val;
    last_val = p[0] = a[0];
    float ai;

    for (i = 1; i < n - 1; i += 2) {

        ai = a[i];
        p[i] = last_val + ai;

        val = last_val + ai + a[i + 1];
        p[i + 1] = val;

        last_val = val;
    }

    for (; i < n; i++) {
        val = last_val + a[i];
        p[i] = val;
        last_val = val;
    }
}


void psum3a(float a[], float p[], long n) {
    
    long i;

    float last_val, val;
    last_val = p[0] = a[0];
    float ai, first_two, temp_val;

    for (i = 1; i < n - 2; i += 3) {
        
        ai = a[i];
        p[i] = last_val + ai;
        
        first_two = ai + a[i + 1];
        temp_val = last_val + first_two;
        p[i + 1] = temp_val;

        val = temp_val + a[i + 2];
        p[i + 2] = val;
        last_val = val;
    }

    for (; i < n; i++) {
        val = last_val + a[i];
        p[i] = val;
        last_val = val;
    }
}

