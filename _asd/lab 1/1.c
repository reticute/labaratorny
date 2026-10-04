#include <stdio.h>

int main() {
    double x, y;

    printf("Enter the number x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        y = -x * x - 12;
        printf("The result is: %g\n", y);
    } else if (x <= 2) {
        printf("Error.\n");
    } else if (x <= 12) {
        y = -9 * x * x * x + 5 * x * x;
        printf("The result is: %g\n", y);
    } else if (x <= 22) {
        printf("Error.\n");
    } else if (x < 32) {
        y = -9 * x * x * x + 5 * x * x;
        printf("The result is: %g\n", y);
    } else {
        printf("Error.\n");
    }

    return 0;
}