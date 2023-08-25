#include <stdio.h>
#define N 4

// This function stores transpose of A[][] in B[][]
void transposta(int A[][N], int B[][N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			B[i][j] = A[j][i];
}

// Driver code
int main()
{
	int A[N][N] = { { 1, 1, 1, 1 },
  					      { 2, 2, 2, 2 },
        					{ 3, 3, 3, 3 },
        					{ 4, 4, 4, 4 } };

  printf("Matriz inicial \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
      
	// Note dimensions of B[][]
	int B[N][N];

	// Function call
	transposta(A, B);

	printf("Matriz final \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", B[i][j]);
		printf("\n");
	}

	return 0;
}
