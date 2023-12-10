#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
	int src;
	int dest;
	int weight;
}Edge;

typedef struct Graph {

	int adjMat[101][101];

}Graph;

Edge* edges;
int visited[101];
int dist[101];

void initGraph(Graph* graph) {

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) {
				graph->adjMat[i][j] = 0;
			}
			else {
				graph->adjMat[i][j] = 999999;
			}
		}
	}
}

void insertEdge(Graph* graph, int edgeNum) {

	int weight, vertex1, vertex2;	

	edges = (Edge*)malloc(sizeof(Edge) * edgeNum);

	for (int i = 0; i < edgeNum; i++) {
		scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
		graph->adjMat[edges[i].src][edges[i].dest] = edges[i].weight;
	}

	return;
}

void bellmanFord(Graph* graph,int edgeNum, int vertexNum ,int startVertex) {

	dist[startVertex] = 0;
	int src, dest, weight;

	for (int i = 0; i < vertexNum + 1; i++) {
		for (int j = 0; j < edgeNum; j++) {
			src = edges[j].src;
			dest = edges[j].dest;
			weight = edges[j].weight;

			if (dist[src] != 999999 && dist[src] + weight < dist[dest]) {
				dist[dest] = dist[src] + weight;
			}
		}
	}
}

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	
	int vertexNum, edgeNum, startVertex;

	for (int i = 0; i < 101; i++) {
		visited[i] = 0;
		dist[i] = 999999;
	}
	scanf("%d %d %d", &vertexNum, &edgeNum, &startVertex);
	initGraph(graph);
	insertEdge(graph, edgeNum);

	bellmanFord(graph, edgeNum, vertexNum, startVertex);

	for (int i = 1; i < vertexNum + 1; i++) {
		if (i == startVertex || dist[i] == 999999) {
			continue;
		}
		printf("%d %d\n", i, dist[i]);
	}
}