#include <stdio.h>
#include <math.h>

int main ()
{
    int n, i, ct;
    ct = 0;
    double S, P;
    S = 0;
    P = 1;
    printf("Enter n: \n");
    scanf("%d", &n);
    ct += 2;
    if (n > 0)
    {
        for (i = 1; i <= n; i++)
        {
            P *= (2 * i + 1);
            S += P / (3 * i * log(i + 1));
            ct += 12; 
        }
        printf("The result is %.7f\n", S);
        ct++;
    }

    printf("Operation count = %d\n", ct);
    return 0;
}
