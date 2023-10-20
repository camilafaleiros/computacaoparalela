#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void); //thread function

int main(int argc, char* argv[]) {
    //get number of threads from command line
    int thread_count = strtol(argv[1], NULL, 10);

    #pragma omp parallel num_threads(thread_count)
    Hello();

    return 0;
} //main

void Hello(void) {
    int my_rank = omp_get_thread_num(); //qual a thread atual
    int thread_count = omp_get_num_threads(); //quantas threads estão em execução

    printf("Hello from thread %d of %d\n", my_rank, thread_count);

} //Hello
