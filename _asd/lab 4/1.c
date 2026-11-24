#include <stdio.h>
#include <stdbool.h>

#define MAX_M 10
#define MAX_N 10

int binarySearch(double A[MAX_M][MAX_N], int m, int col, double minVal, double maxVal) {
    int L = 0;
    int R = m - 1;
    int mid;

    while (L <= R) {
        mid = (L + R) / 2;
        if (A[mid][col] >= minVal && A[mid][col] <= maxVal) {
            return mid; 
        }
        else if (A[mid][col] > maxVal) {
            // > 5
            L = mid + 1;
        } else {
            // < 0
            R = mid - 1;
        }
    }
    return -1;
}

void findInMatrix(double A[MAX_M][MAX_N], int m, int n) {
    printf("\n*** Matrix (%dx%d) ***\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7.2f ", A[i][j]);
        }
        printf("\n");
    }

    bool found = false;
    int foundRow = -1, foundCol = -1;
    for (int j = 0; j < n; j++) {
        int row = binarySearch(A, m, j, 0.0, 5.0);
        if (row != -1) {
            found = true;
            foundRow = row;
            foundCol = j;
            break; 
        }
    }

    if (found) {
        printf("Result: found element %.2f in range [0, 5]\n", A[foundRow][foundCol]);
        printf("Coordinates: row %d, col %d\n", foundRow, foundCol);
    } else {
        printf("Result: no elements in range [0, 5] found\n");
    }
}

int main() {
    // матриця 8х8
    double test1[MAX_M][MAX_N] = {
        { 25.4,  18.0,  15.5,  30.1,  12.0,  40.0,   9.5,  50.2},
        { 20.1,  15.2,  12.0,  22.4,  10.5,  33.2,   8.1,  41.0},
        { 15.0,  12.8,   9.4,  19.0,   9.8,  25.0,   7.4,  30.5},
        { 12.3,  10.1,   6.2,  14.5,   8.2,  18.7,   6.0,  20.0},
        {  9.8,   8.5,   3.5,  11.2,   7.0,  12.1,  -1.2,  15.4}, // A[4][2] = 3.50 є [0, 5]
        {  7.5,   6.0,  -2.1,   8.9,   6.1,   9.5,  -4.5,  10.2},
        {  6.1,  -0.5,  -5.0,   6.5,  -1.0,   7.3,  -8.0,   8.0},
        { -3.4,  -4.2,  -9.8,  -2.0,  -5.5,   5.8, -12.3,   6.4}
    };
    printf("Matrix 1: 8x8");
    findInMatrix(test1, 8, 8);

    // матриця 4x4
    double test2[MAX_M][MAX_N] = {
        { 12.0,  10.0,   5.0,   8.0}, // A[0][2] = 5.00 є [0, 5]
        {  9.5,   7.2,   2.1,   6.5},
        {  6.1,  -1.0,   0.0,  -2.3},
        { -3.0,  -5.4,  -4.2,  -9.1}
    };
    printf("\nMatrix 2: 4x4");
    findInMatrix(test2, 4, 4);

    // відсутність елементів з діапазону [0, 5]
    double test3[MAX_M][MAX_N] = {
        { 15.0,  12.5,   9.0,  20.0},
        { 10.2,   8.4,   6.1,  11.5},
        {  6.0,  -0.1,  -1.5,   5.1},
        { -2.5,  -4.0,  -8.2,  -0.5}
    };
    printf("\nMatrix 3: no elements in range");
    findInMatrix(test3, 4, 4);

    return 0;
}