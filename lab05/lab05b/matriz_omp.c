#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int l = 10, c = 10;
int v[10] = {1, 2, 3, 4, 5, 2, 6, 3, 4, 3};
int m[10][10] = {
    {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
    {6, 6, 7, 7, 8, 8, 9, 9, 10, 10},
    {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
    {6, 6, 7, 7, 8, 8, 9, 9, 10, 10},
    {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
    {6, 6, 7, 7, 8, 8, 9, 9, 10, 10},
    {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
    {6, 6, 7, 7, 8, 8, 9, 9, 10, 10},
    {1, 1, 2, 2, 3, 3, 4, 4, 5, 5},
    {6, 6, 7, 7, 8, 8, 9, 9, 10, 10}};
int r[10];

void createThread() {
    int i, j;
    #pragma omp parallel
    {
        #pragma omp for
        for (i = 0; i < l; i++) {
            int partial_result = 0;
            for (j = 0; j < c; j++) {
                partial_result += m[i][j] * v[j];
            }
            r[i] = partial_result;
        }
    }
}

int main() {
    double start_time, end_time;
    start_time = omp_get_wtime();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("M[%i][%i]: ", i, j);
            printf("%d  ", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        printf("V[%i]: ", i);
        printf("%d\n", v[i]);
    }

    createThread();

    printf("Result:\n");
    for (int i = 0; i < l; i++) {
        printf("R[%i]: %d\n", i, r[i]);
    }

    end_time = omp_get_wtime();
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}

