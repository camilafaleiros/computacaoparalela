#include <stdio.h>

void multSerial(int vector[], int matrix[][10], int result[], int lines, int columns) {
  for (int i = 0; i < lines; i++) {
    result[i] = 0;

    for (int j = 0; j < columns; j++) {
      result[i] += vector[j] * matrix[i][j];
    }
  }
  
  for (int i = 0; i < 10; i++){
      printf("R[%i]: ", i);
      printf("%d\n", result[i]);
  }
}

int main() {
  int l = 10, c = 10;
  int v[10];
  int m[10][10] = {{1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10},
			  {1,1,2,2,3,3,4,4,5,5},
			  {6,6,7,7,8,8,9,9,10,10}};
  int r[10];
  
  for(int i = 0; i < l; i++){
    v[i] = i;
    for(int j = 0; j < c; j++){
      m[i][j] = j;
    }
  }
 
  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("M[%i][%i]: ", i, j);
            printf("%d\n", m[i][j]);
        }
  }
 
  for (int i = 0; i < 10; i++){
    printf("V[%i]: ", i);
    printf("%d\n", v[i]);
  }

  printf("Multiplicação da Matriz M pelo vetor V: ");

  multSerial(v, m, r, l, c);
  
}


