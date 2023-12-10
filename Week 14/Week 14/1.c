#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {

	int vertexNum;
	int adjMat[101][101];

}Graph;

int visited[101];
int dist[101];
int vertexNum;

void initGraph(Graph* graph) {

	graph->vertexNum = vertexNum;
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

void insertEdge(Graph* graph, int vertex1, int vertex2, int weight) {


	graph->adjMat[vertex1][vertex2] = weight;
	graph->adjMat[vertex2][vertex1] = weight;

	return;
}

int returnSmallIndex() {

	int min = 999999;
	int index = 0;
	for (int i = 0; i < vertexNum+1; i++) {
		if (dist[i] < min && !visited[i]) {
			min = dist[i];
			index = i;
		}
	}

	return index;
}

void dijkstra(Graph* graph, int startVertex) {

	int currentVertex;

	for (int i = 0; i < vertexNum+1; i++) {
		dist[i] = graph->adjMat[startVertex][i];
	}

	visited[startVertex] = 1;

	for (int i = 0; i < vertexNum - 1; i++) {
		currentVertex = returnSmallIndex();
		visited[currentVertex] = 1;
		for (int j = 0; j < vertexNum + 1; j++) {
			if (!visited[j]) {
				if (dist[currentVertex] + graph->adjMat[currentVertex][j] < dist[j]) {
					dist[j] = dist[currentVertex] + graph->adjMat[currentVertex][j];
				}
			}
		}
	}
}

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	int weight, vertex1, vertex2;
	int edgeNum, startVertex;

	for (int i = 0; i < 101; i++) {
		visited[i] = 0;
		dist[i] = 999999;
	}
	scanf("%d %d %d", &vertexNum, &edgeNum, &startVertex);
	initGraph(graph);

	for (int i = 0; i < edgeNum; i++) {
		scanf("%d %d %d", &vertex1, &vertex2, &weight);
		insertEdge(graph, vertex1, vertex2, weight);
	}

	dijkstra(graph, startVertex);

	for (int i = 1; i < vertexNum + 1; i++) {
		if (i == startVertex || dist[i] == 999999) {
			continue;
		}
		printf("%d %d\n", i, dist[i]);
	}
}