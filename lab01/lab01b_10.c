#include <stdio.h>
#include <string.h>
#define N 4
#define M 4

void mult_matrix_l(int A[M][N])
{
  int i, j, n, l;
  printf("Inserir um valor: ");
  scanf("%d", &n);

  printf("Linha a ser multiplicada: ");
  scanf("%d", &l);
  
  for (i = 0; i < M; i++)
  {
    for (j = 0; j < N; j++)
      {
        if (i == l)
          A[i][j] = A[i][j]*n;
      }
  }
}

void mult_matrix_c(int A[M][N])
{
  int i, j, n, c;
  printf("Inserir um valor: ");
  scanf("%d", &n);

  printf("Coluna a ser multiplicada: ");
  scanf("%d", &c);
  
  for (i = 0; i < M; i++)
  {
    for (j = 0; j < N; j++)
      {
        if (j == c)
          A[i][j] = A[i][j]*n;
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

  printf("Matriz inicial \n");
	print_matrix(A);

  printf("Multiplicar linha\n");
  mult_matrix_l(A);
  print_matrix(A);

  printf("Multiplicar coluna\n");
  mult_matrix_c(A);
  print_matrix(A);
}
