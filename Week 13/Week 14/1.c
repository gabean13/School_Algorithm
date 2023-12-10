#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int VertexNum, EdgeNum;
int* dist;
int* visited;

typedef struct Graph {

	int vertexNum;
	int** adjMat;

}Graph;

void initGraph(Graph* graph) {

	VertexNum++;

	graph->adjMat = (int**)malloc(sizeof(int*) * VertexNum);
	for (int i = 0; i < VertexNum; i++) {
		*(graph->adjMat + i) = (int*)malloc(sizeof(int) * VertexNum);
	}


	for (int i = 0; i < VertexNum; i++) {
		for (int j = 0; j < VertexNum; j++) {
			graph->adjMat[i][j] = 999999;
		}
	}

	graph->vertexNum = VertexNum - 1;
}

void insertEdge(Graph* graph, int vertex1, int vertex2, int weight) {

	graph->adjMat[vertex1][vertex2] = weight;
	graph->adjMat[vertex2][vertex1] = weight;

	return;
}

int returnMinVertex() {

	int vertex = 0;

	for (int i = 1; i < VertexNum; i++) {
		if (!visited[i]) {
			vertex = i;
			break;
		}
	}

	for (int i = 0; i < VertexNum; i++) {
		if (!visited[i] && (dist[i] < dist[vertex])) {
			vertex = i;
		}
	}

	return vertex;
}

void primMST(Graph* graph) {

	int minVertex;
	

	for (int i = 0; i < VertexNum; i++) {
		dist[i] = 999999;
		visited[i] = 0;
	}

	dist[1] = 0;

	for (int i = 0; i < VertexNum; i++) {

		minVertex = returnMinVertex();
		visited[minVertex] = 1;

		if (dist[minVertex] == 999999) {
			return;
		}

		printf("%d ", minVertex);
		for (int i = 0; i < VertexNum; i++) {
			if (graph->adjMat[minVertex][i] != 999999) {
				if (!visited[i] && graph->adjMat[minVertex][i] < dist[i]) {
					dist[i] = graph->adjMat[minVertex][i];
				}
			}
		}		
	}
}

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	int vertex1, vertex2, weight;
	int totalWeight = 0;

	scanf("%d %d", &VertexNum, &EdgeNum);

	initGraph(graph);

	visited = (int*)malloc(sizeof(int) * VertexNum);
	dist = (int*)malloc(sizeof(int) * VertexNum);

	for (int i = 0; i < EdgeNum; i++) {
		scanf("%d %d %d", &vertex1, &vertex2, &weight);
		insertEdge(graph, vertex1, vertex2, weight);
	}
	
	primMST(graph);

	for (int i = 1; i < VertexNum; i++) {
		totalWeight += dist[i];
	}

	printf("\n%d", totalWeight);
}