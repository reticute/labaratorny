#include <stdio.h>

int main() {
    int n, T, j;

    printf("Size of the square matrix (n): \n");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter elements of the matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int col = 0; col < n; col++) {
            scanf("%d", &matrix[i][col]);
        }
    }

    printf("Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int col = 0; col < n; col++) {
            printf("%d\t", matrix[i][col]);
        }
        printf("\n");
    }

    // сортування головної діагоналі 
    for (int i = 1; i < n; i++) {
        T = matrix[i][i];
        j = i;
        while (j > 0 && matrix[j - 1][j - 1] > T) {
            matrix[j][j] = matrix[j - 1][j - 1];
            j = j - 1;
        }
        matrix[j][j] = T;
    }

    printf("Sorted matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int col = 0; col < n; col++) {
            printf("%d\t", matrix[i][col]);
        }
        printf("\n");
    }

    return 0;
}