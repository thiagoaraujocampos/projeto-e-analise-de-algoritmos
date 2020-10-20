#include <limits.h>
#include <stdio.h> 
#include <float.h>

/*
9 12 4 2
0 1 1.3 0 5 1.5 0 4 3.2 1 2 0.7 1 3 0.3 2 3 2.3 4 9 0.2 5 6 1.7 5 7 3.0 6 7 0.9 6 8 2.1 7 8 1.1
8 7 7 5 5 8 2 3
2
8
*/

int minDistance(double dist[], int tam, bool sptSet[]) 
{ 
	double min = DBL_MAX, min_index; 
	for (int v = 0; v < tam; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 
	return min_index; 
} 

void dijkstra(double graph[], int vent[], int N, int tam, int src) 
{ 
	double dist[tam];
	bool sptSet[tam];

	double resultado[2];

	double copia[tam][tam];

	for (int i=0; i<tam; i++) {
		for (int j=0; j<tam; j++) {
			copia[i][j] = *(graph + i*tam + j);
		}
	}

	for (int i = 0; i < tam; i++) 
		dist[i] = DBL_MAX, sptSet[i] = false;

	dist[src] = 0.0; 

	for (int count = 0; count < tam - 1; count++) { 
		int u = minDistance(dist, tam, sptSet); 
 
		sptSet[u] = true; 
 
		for (int v = 0; v < tam; v++) {
			if (!sptSet[v] && copia[u][v] != 0.0 && dist[u] != DBL_MAX && dist[u] + copia[u][v] < dist[v]) {
				dist[v] = dist[u] + copia[u][v]; 
			}
		}
	} 

	resultado[0] = dist[0];

	for (int j=0; j<N*2; j=j+2) {
		//printf("VENT? %.1lf\n", copia[vent[j]][vent[j+1]]);
		if (copia[vent[j]][vent[j+1]] >= 1.0 || copia[vent[j]][vent[j+1]] <= 0.0) {
			copia[vent[j]][vent[j+1]] = 1.0; 
			copia[vent[j+1]][vent[j]] = 1.0;
		}
	}

	for (int i = 0; i < tam; i++) 
		dist[i] = DBL_MAX, sptSet[i] = false; 

	dist[src] = 0.0;

	for (int count = 0; count < tam - 1; count++) { 
		int u = minDistance(dist, tam, sptSet); 
 
		sptSet[u] = true; 
 
		for (int v = 0; v < tam; v++) {
			if (!sptSet[v] && copia[u][v] != 0.0 && dist[u] != DBL_MAX && dist[u] + copia[u][v] < dist[v]) {
				dist[v] = dist[u] + copia[u][v]; 
			}
		}
	} 

	resultado[1] = dist[0];

	if (resultado[1] >= (resultado[0] - 0.01)) {
		printf("victory\n");
	} else {
		printf("defeat\n");
	}
 
} 

int main() 
{ 
	int M, E, N, C, i, j, x, y, inicio;
  double p;
  
  scanf("%d %d %d %d", &M, &E, &N, &C);

  double mapa[M+1][M+1];
	int vent[N*2];

  for (i=0; i<=M; i++) {
    for (j=0; j<=M; j++) {
      mapa[i][j] = 0;
    }
  }

  for (i=0; i<E; i++) {
    scanf("%d %d %lf", &x, &y, &p);
    mapa[x][y] = p;
    mapa[y][x] = p;
  }

	for (i=0; i<N*2; i++) {
		scanf("%d", &vent[i]);
	}

	for (i=0; i<C; i++) {
		scanf("%d", &inicio);	
		dijkstra(&mapa[0][0], vent, N, M+1, inicio);
	}

	return 0; 
} 