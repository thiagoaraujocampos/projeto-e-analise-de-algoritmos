// Thiago Araujo Campos - 769850
/*
#include <iostream>
using namespace std;

void print(double *mapa) {
  int i, j, M=12;

  for (i=0; i<M; i++) {
    for (j=0; j<M; j++) {
      printf("%.1lf ", *(mapa + i*12 + j));
    }
    printf("\n");
  }

}

int main()
{
  int M = 12, i, j;
	double mapa[M][M];

  for (i=0; i<M; i++) {
    for (j=0; j<M; j++) {
      mapa[i][j] = 1;
    }
  }

  mapa[0][0] = 5;
  printf("\n\n");

  print(mapa[0])  ;
  
	return 0;
}
*/


// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <limits.h> 
#include <stdio.h> 

// Number of vertices in the graph 
#define V 9

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(double dist[], bool sptSet[]) 
{ 
	// Initialize min value 
	double min = INT_MAX;
  int min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the constructed distance array 
void printSolution(double dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(double *graph, int src) 
{ 

  for (int i=0; i<V; i++) {
    for (int j=0; j<V; j++) {
      printf("%.1lf ", *(graph + i*V + j));
    }
    printf("\n");
  }
	double dist[V]; // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX, sptSet[i] = false; 
    printf("%d\n", INT_MAX);
  }

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices 
	for (int count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet); 

		// Mark the picked vertex as processed 
		sptSet[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++) 

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
			if (!sptSet[v] && *(graph + u*V + v) && dist[u] != INT_MAX 
				&& dist[u] + *(graph + u*V + v) < dist[v]) 
				dist[v] = dist[u] + *(graph + u*V + v); 
	} 

	// print the constructed distance array 
	printSolution(dist); 
} 

// driver program to test above function 
int main() 
{ 
  int M, E, N, C, i, j, x, y, inicio;
  double p;
  
  scanf("%d %d %d %d", &M, &E, &N, &C);

  double mapa[V][V];

  for (i=0; i<V; i++) {
    for (j=0; j<V; j++) {
      mapa[i][j] = 0;
    }
  }

  for (i=0; i<E; i++) {
    scanf("%d %d %lf", &x, &y, &p);
    printf("%d %d %.1lf ",x, y, p);
    mapa[x][y] = p;
    mapa[y][x] = p;
  }

	/* Let us create the example graph discussed above */
	//int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
	//					{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
	//					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
	//					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
	//					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
	//					{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
	//					{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
	//					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
	//					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	dijkstra(mapa[0], 0); 

	return 0; 
} 
