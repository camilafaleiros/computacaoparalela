#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x) {
    return exp(x);
}

double Trap(int n, double a, double b) {
    double h = (b - a) / n;
    double result = 0.0;

    result += f(a) / 2.0; // Adiciona a primeira parte
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        result += f(x);
    }
    result += f(b) / 2.0; // Adiciona a última parte

    result *= h;

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_trapezoids>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double a, b;

    printf("Enter a, b, and n\n");
    if (scanf("%lf %lf %d", &a, &b, &n) != 3) {
        printf("Invalid input. Please enter valid values for a, b, and n.\n");
        return 1;
    }

    double result = 0.0;

    clock_t start_time = clock();

    #pragma omp parallel num_threads(1)
    {
        double local_result = Trap(n, a, b);

        #pragma omp critical
        result += local_result;
    }

    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n", a, b, result);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

