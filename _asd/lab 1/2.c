#include <stdio.h>

int main() {
    double x, y;

    printf("Enter the number x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        y = -x * x - 12;
        printf("The result is: %g\n", y);
    } else if ((x > 2 && x <= 12) || (x > 22 && x < 32)) {
        y = -9 * x * x * x + 5 * x * x;
        printf("The result is: %g\n", y);
    } else {
        printf("Error.\n");
    }

    return 0;
}