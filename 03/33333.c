#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x;
}

double compositeMidpoint(double a, double b, int N) {
    double h = (b - a) / N;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return h * sum;
}

double compositeSimpson(double a, double b, int N) {
    double h = (b - a) / N;
    double sum = f(a) + f(b);
    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return (h / 3) * sum;
}

int main() {
    double a = 0, b = 1;
    int N_values[] = {16, 32, 64, 128, 256, 512, 1024};
    double exact_value = 1.0 / 3.0;

    printf("N\tMidpoint\tError\t\tSimpson\t\tError\n");
    for (int i = 0; i < 7; i++) {
        int N = N_values[i];
        double midpoint_result = compositeMidpoint(a, b, N);
        double simpson_result = compositeSimpson(a, b, N);
        double midpoint_error = fabs(midpoint_result - exact_value);
        double simpson_error = fabs(simpson_result - exact_value);
        printf("%d\t%.8f\t%.8f\t%.8f\t%.8f\n", N, midpoint_result, midpoint_error, simpson_result, simpson_error);
    }

    return 0;
}