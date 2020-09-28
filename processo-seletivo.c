#include <stdio.h>
#include <stdlib.h>

int funcao_que_resolve() {

}

void mergeSort() {

}

void merge() {
	
}

int main() {
  int C, K, N;
  double R[1000001];

  scanf("%d ", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d ", &K, &C);

    for (int j = 0; j < C; j++)
      scanf("%lf ", &R[j]);

      double sol = funcao_que_resolve();
      printf("%.2lf\n", sol);
    }

  return 0; 
} 