// Thiago Araujo Campos - 769850

#include <iostream>
using namespace std;

#define max 4294967295

int shortestPath(double c[], int tam, bool f[]) {
  int i, index; 
  double min = max;

  for (i=0; i<tam; i++) {
    if (f[i] == false and c[i] <= min) {
      min = c[i];
      index = i;
    }
  }

  return index;
}

double dijkstra(double *grafo, int tam, int inicio) {

  /*printf("\n\n%d %d\n\n", tam, inicio);
  for (int i=0; i<tam; i++) {
    for (int j=0; j<tam; j++) {
      printf("%.1lf ", *(grafo + i*tam + j));
    }
    printf("\n");
  }*/

  int i;
  double c[tam];
  bool f[tam];

  for (i=0; i<tam; i++) {
    c[i] = max;
    f[i] = false;
  }

  c[inicio-1] = 0;

  for (i=0; i<tam-1; i++) {
    int atual = shortestPath(c, tam, f);
    f[atual] = true;

    for (int j=0; j<tam; j++) {
      if (!f[atual] && *(grafo + atual*tam + j) != -1 && c[atual] != max && c[atual] + *(grafo + atual*tam + j) < c[j]) {
        c[j] = c[atual] + *(grafo + atual*tam + j);
      }
    }
  }

  return c[0];
}

int main()
{
	int M, E, N, C, i, j, x, y, inicio;
  double p;
  
  scanf("%d %d %d %d", &M, &E, &N, &C);

  double mapa[M][M];

  for (i=0; i<M; i++) {
    for (j=0; j<M; j++) {
      mapa[i][j] = -1;
    }
  }

  for (i=0; i<E; i++) {
    scanf("%d %d %lf", &x, &y, &p);
    printf("%d %d %.1lf ",x, y, p);
    mapa[x][y] = p;
    mapa[y][x] = p;
  }

  scanf("%d", &inicio);

  double fim = dijkstra(mapa[0], M, inicio);
  printf("%.1lf", fim);

	return 0;
}