#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
double a, b;
    int n;
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input b: ");
    scanf("%lf", &b);
    printf("Input n: ");
    scanf("%d", &n);

    if (n <= 0 || a >= b) {
        printf("n must be > 0, a must be < b.\n");
        return 1;
    }
    srand((unsigned int)time(NULL)); //random number generator

    double *Y = (double*)malloc(n * sizeof(double));
    double *Z = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        double random_0_1 = (double)rand() / RAND_MAX;
        Y[i] = a + random_0_1 * (b - a);
    }

    for (int i = 0; i < n; i++) {
        if (Y[i] > -50.0 && Y[i] < 0.0) {
            Z[i] = 10.0 * a - Y[i];
        } else {
            Z[i] = 1.0 + Y[i] * Y[i];
        }
    }
    double R = 0.0;
    for (int i = 0; i < n; i++) {
        int i_math = i + 1; 
        double term = pow(-1.0, i_math) * b + Z[i];
        
        if (i == 0 || term > R) {
            R = term;
        }
    }
    printf("Input data:\n");
    printf("a = %.3f, b = %.3f, n = %d\n\n", a, b, n);
    printf("Initial array Y[n]:\n");
    for (int i = 0; i < n; i++) {
        printf("Y[%d] = %.3f\n", i, Y[i]);
    }
    printf("\nIntermediate array Z[n]:\n");
    for (int i = 0; i < n; i++) {
        printf("Z[%d] = %.3f\n", i, Z[i]);
    }

    printf("\nResulting R value:\n");
    printf("R = %.3f\n", R);

    free(Y);
    free(Z);
    return 0;
}

