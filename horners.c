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

/* Evaluation of a polynomial by Horner's method */
double polyh(double a[], double x, long degree) {
    
    long i;
    double result = a[degree];
    for (i = degree - 1; i >= 0; i--) {
        result = a[i] + x * result;
    }
    return result;
}
