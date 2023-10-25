#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x) {
    return exp(x);
}

double Trap(double a, double b, int n) {
    double h = (b - a) / n;
    double result = (f(a) + f(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        result += f(x);
    }
    
    result *= h;
    
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_trapezoids>\n", argv[0]);
        return 1;
    }

    double a = 0.0;
    double b = 1.0;
    int n = atoi(argv[1]);

    clock_t start_time = clock();

    double result = Trap(a, b, n);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n", a, b, result);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

