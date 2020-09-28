// Thiago Araujo Campos - 769850

#include <stdio.h> 
#include <stdlib.h> 

void merge(double R[], int esq, int meio, int dir) {
    int i, j;
    double *aux;
    aux = (double *) malloc((dir-esq) * sizeof(double));

    for(i = esq; i < meio; ++i){
        aux[i-esq] = R[i];
    }
    for(j = meio; j < dir; ++j){
        aux[dir-esq + meio-j-1] = R[j];
    }

    i = 0;
    j = dir - esq - 1;
    for(int k = esq; k < dir; ++k){
        if (aux[i] >= aux[j]){
            R[k] = aux[i++];
        } else {
            R[k] = aux[j--];
        }
    }
    free(aux);
}

void sort(double R[], int esq, int dir) {
    if(esq < dir-1){
        int meio = (esq + dir)/2;
        sort(R, esq, meio);
        sort(R, meio, dir);
        merge(R, esq, meio, dir);
    }
}

double soluciona(double R[], int K, int C) {
    sort(R, 0, C);
    return R[K-1];
}

int main() {
    int C, K, N;
    double R[1000001];

    scanf("%d ",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d ", &K, &C);

        for(int j=0;j<C;j++)
          scanf("%lf ", &R[j]);

        double sol = soluciona(R, K, C);
        printf("%.2lf\n", sol);
    }

    return 0;
}
