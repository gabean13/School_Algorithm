#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {

	int vertexNum;
	int adjMat[6][6];

}Graph;

void initGraph(Graph* graph) {

	graph->vertexNum = 6;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			graph->adjMat[i][j] = 0;
		}
	}
}

void printAdjList(Graph* graph, int vertex) {

	vertex--;

	if (vertex > 5 || vertex < 0) {
		printf("-1 \n");
		return;
	}

	for (int i = 0; i < 6; i++) {
		if (graph->adjMat[vertex][i] != 0) {
			printf(" %d %d", i + 1, graph->adjMat[vertex][i]);
		}
	}

	printf("\n");
}

void insertEdge(Graph* graph, int vertex1, int vertex2, int weight) {

	vertex1--;
	vertex2--;

	if (vertex1 > 5 || vertex1 < 0 || vertex2 > 5 || vertex2 < 0) {
		printf("-1\n");
		return;
	}

	graph->adjMat[vertex1][vertex2] = weight;
	graph->adjMat[vertex2][vertex1] = weight;

	return;
}

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	char cmd;
	int nodeNum, weight, vertex1, vertex2;

	initGraph(graph);

	insertEdge(graph, 1, 2, 1);
	insertEdge(graph, 1, 3, 1);
	insertEdge(graph, 1, 4, 1);
	insertEdge(graph, 1, 6, 2);

	insertEdge(graph, 2, 3, 1);
	
	insertEdge(graph, 3, 5, 4);

	insertEdge(graph, 5, 5, 4);
	insertEdge(graph, 5, 6, 3);


	while (1) {
		scanf("%c", &cmd);
		if (cmd == 'a') {
			scanf("%d", &nodeNum);
			printAdjList(graph, nodeNum);
		}
		else if (cmd == 'm') {
			scanf("%d %d %d", &vertex1, &vertex2, &weight);
			insertEdge(graph, vertex1, vertex2, weight);
		}
		else if (cmd == 'q') {
			break;
		}
		getchar();
	}

	return;
}