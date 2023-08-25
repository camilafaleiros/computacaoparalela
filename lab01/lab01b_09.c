#include <stdio.h>
#define N 4
#define M 

void mod_matriz(int A[M][N])
{
  int i, j;
  for (i = 0; i < M; i++)
  {
    for (j = 0; j < N; j++)
      {
        if (A[i][j] < 0) 
          A[i][j] = A[i][j] * (-1);
      }
  }
}

// Driver code
int main()
{
	int A[N][N] = { { 1, 1, 1, 1 },
  					      { 2, 2, 2, 2 },
        					{ 3, -3, 3, 3 },
        					{ 4, 4, -4, 4 } };

  mod_matriz(A);
  

 printf("Matriz com módulo  \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
return 0;
}

