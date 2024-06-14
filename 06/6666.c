#include <stdio.h>

void matrixmultiply(double *a, double *b, double *c, int m, int n, int p) {
    // Perform matrix multiplication A * B = C
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += a[i * n + k] * b[k * p + j];
            }
            c[i * p + j] = sum;
        }
    }
}

int main() {
    // Example matrices A (2x3) and B (3x2)
    double A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    double B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    double C[2][2];

    int m = 2; // rows of A
    int n = 3; // columns of A, rows of B
    int p = 2; // columns of B

    // Convert matrices A and B to 1D arrays for the function
    double a[m * n], b[n * p], c[m * p];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i * n + j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            b[i * p + j] = B[i][j];
        }
    }

    // Call matrix multiplication function
    matrixmultiply(a, b, c, m, n, p);

    // Print result matrix C
    printf("Result matrix C:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%.2f\t", c[i * p + j]);
        }
        printf("\n");
    }

    return 0;
}