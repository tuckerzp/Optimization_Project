/**
 * Attempt to optimize horner's method
 *
 * Author: Zach Tucker & Ryan Showalter
 * Version: 11122019
 */

/* Direct Polynomial evaluation */ 
double poly(double a[], double x, long degree) {
   
    long i;
    double result = a[0];
    double xpwr = x; /* Equals x^i at start of loop */
    for (i = 1; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }
    return result;
}

double unroll2_poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    double x_squared = x * x;
    
    for (i = 1; i + 1 <= degree; i += 2) {
        result += a[i] * xpwr;
        result += a[i + 1] * xpwr * x;
        xpwr = x_squared * xpwr;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }

    return result;
}

double unroll2x2_poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    double x_squared = x * x;

    double acc0 = 0;
    double acc1 = 0;

    for (i = 1; i + 1 < degree; i += 2) {
        acc0 += a[i] * xpwr;
        acc1 += a[i + 1] * xpwr * x;
        xpwr = x_squared * xpwr;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }

    return result + acc0 + acc1;

}

double unroll4_poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    double x_squared = x * x;
    double x_cubed = x * x_squared;
    double x4 = x * x_cubed;
    
    for (i = 1; i + 3 <= degree; i += 4) {
        result += a[i] * xpwr;
        result += a[i + 1] * xpwr * x;
        result += a[i + 2] * xpwr * x_squared;
        result += a[i + 3] * xpwr * x_cubed;
        xpwr = x4 * xpwr;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }

    return result;
}

double unroll4x4_poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    double x_squared = x * x;
    double x_cubed = x * x_squared;
    double x4 = x * x_cubed;
   
    double acc0 = 0;
    double acc1 = 0;
    double acc2 = 0;
    double acc3 = 0;

    for (i = 1; i + 3 <= degree; i += 4) {
        acc0 += a[i] * xpwr;
        acc1 += a[i + 1] * xpwr * x;
        acc2 += a[i + 2] * xpwr * x_squared;
        acc3 += a[i + 3] * xpwr * x_cubed;
        xpwr = x4 * xpwr;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }

    return result + (acc0 + acc1) + (acc2 + acc3);
}

double unroll2a_poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    double x2 = x * x;

    for (i = 1; i <= degree - 1; i += 2) {
        result += (a[i] + x * a[i + 1]) * xpwr;
        xpwr *= x2;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }

    return result;
}

double unroll4a_poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x2 * x2;

    for (i = 1; i <= degree - 3; i += 4) {
        result += ((a[i] + x * a[i + 1]) + (x2 * a[i + 2] + x3 * a[i + 3])) * xpwr;
        xpwr *= x4;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr *= x;
    }

    return result;

}

double unroll2a_poly_mix(double a[], double x, long degree) {
    long i;
    double acc0 = a[0];
    double xpwr = x;

    double acc1 = 0;
    
    double x2 = x * x;

    for (i = 1; i <= degree - 1; i += 2) {
        acc0 += a[i] * xpwr;
        acc1 += a[i + 1] * xpwr;
        xpwr *= x2;
    }

    acc0 += x * acc1;

    for (; i <= degree; i++) {
        acc0 += a[i] * xpwr;
        xpwr *= x;
    }

    return acc0;
}

double unroll4a_poly_mix(double a[], double x, long degree) {
    long i;
    double acc0 = a[0];
    double xpwr = x;
    double x4 = (x * x) * (x * x);

    double acc1 = 0;
    double acc2 = 0;
    double acc3 = 0;

    for (i = 1; i <= degree - 3; i += 4) {
        acc0 += a[i] * xpwr;
        acc1 += a[i + 1] * xpwr;
        acc2 += a[i + 2] * xpwr;
        acc3 += a[i + 3] * xpwr;
        xpwr *= x4;
    }

    acc0 += x * (acc1 + x * (acc2 + x * acc3));

    for (; i <= degree; i++) {
        acc0 += a[i] * xpwr;
        xpwr *= x;
    }

    return acc0;
}

/* Evaluation of a polynomial by Horner's method */
double polyh(double a[], double x, long degree) {
    
    long i;
    double result = a[degree];
    for (i = degree - 1; i >= 0; i--) {
        result = a[i] + x * result;
    }
    return result;
}

double unroll2_polyh(double a[], double x, long degree) {

    long i;
    double result = a[degree];

    for (i = degree - 1; i >= 1; i -= 2) {
        result = a[i] + (x * result);
        result = a[i - 1] + (x * result);
    }

    for (; i >= 0; i--) {
        result = a[i] + (x * result);
    }

    return result;
}

double unroll4_polyh(double a[], double x, long degree) {
    long i;
    double result = a[degree];

    for (i = degree - 1; i >= 3; i -= 4) {
        result = a[i] + (x * result);
        result = a[i - 1] + (x * result);
        result = a[i - 2] + (x * result);
        result = a[i - 3] + (x * result);
    }

    for (; i >= 0; i--) {
        result = a[i] + (x * result);
    }
}

double unroll2a_polyh(double a[], double x, long degree) {
    long i;
    double x2 = x * x;
    double result = a[degree];

    for (i = degree - 1; i >= 1; i -= 2) {
        result = (a[i - 1] + x * a[i]) + x2 * result;
    }

    for (; i >= 0; i--) {
        result = a[i] + (x * result);
    }

    return result;
}

double unroll4a_polyh(double a[], double x, long degree) {
    long i;
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x2 * x2;
    double result = a[degree];

    for (i = degree - 1; i >= 3; i -= 4) {
        result = ((a[i - 3] + x * a[i - 2]) + (x2 * a[i - 1] + x3 * a[i])) + x4 * result;
    }

    for (; i >= 0; i--) {
        result = a[i] + (x * result);
    }
    
    return result;
}

