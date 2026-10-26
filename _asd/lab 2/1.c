#include <stdio.h>
#include <math.h>

int main ()
{
    int n, i, j, ct;
    ct = 0;
    double S, P;
    S = 0;
    printf("Enter n: \n");
    scanf("%d", &n);
    ct++; 
    if (n > 0)
    {
        for (i = 1; i <= n; i++)
        {
            P = 1;
            for (j = 1; j <= i; j++)
            {
                P *= (2 * j + 1);
                ct += 6; 
            }
            S += P / (3 * i * log(i + 1));
            ct += 11; 
        }
        printf("The result is %.7f\n", S);
        ct++;
    }

    printf("Operation count = %d\n", ct);
    return 0;
}
