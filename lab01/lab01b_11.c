#include <stdio.h>
#include <string.h>
#define N 4
#define M 4

void somar(int A[M][N])
{
  int i, j;
  for (i = 0; i < M; i++)
  {
    for (j = 0; j < N; j++)
      {
        if (i == 1)
          A[i][j] = A[i][j]+A[i-1][j];
      }
  }
}

void print_matrix(int A[M][N])
{
  for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

int main()
{
	int A[N][N] = { { 1, 5, 1, 1 },
  					      { 2, 2, 2, 2 },
        					{ 3, -3, 3, 3 },
        					{ 4, 4, -4, 4 } };

  print_matrix(A);
  printf("Somar linha\ns");
  somar(A);
  print_matrix(A);
}
