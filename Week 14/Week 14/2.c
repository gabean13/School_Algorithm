#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int VertexNum, EdgeNum;

typedef struct Graph {

	int vertexNum;
	int** adjMat;

}Graph;

typedef struct Edge {
	int src;
	int dest;
	int weight;
}Edge;

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

int find(int* parent, int i) {

	if (i < 0 || i > VertexNum) {
		return;
	}

	if (parent[i] == -1) {
		return i;
	}
	parent[i] = find(parent, parent[i]);
	return parent[i];
}

void unionSubset(int* parent, int x, int y) {
	
	int xSet = find(parent, x);
	int ySet = find(parent, y);
	parent[xSet] = ySet;
}

int compare(Edge* a, Edge* b) {

	return a->weight - b->weight;

}

int kruskalMST(Graph* graph) {

	int totalWeight = 0;
	int i = 0;
	int j = 0;
	int count = 0;

	struct Edge* edges = (Edge*)malloc(sizeof(Edge) * VertexNum * VertexNum);

	for (int u = 0; u < VertexNum; u++) {
		for (int v = u + 1; v < VertexNum; v++) {
			if (graph->adjMat[u][v] != 999999) {
				edges[i].src = u;
				edges[i].dest = v;
				edges[i].weight = graph->adjMat[u][v];
				i++;
			}
		}
	}

	qsort(edges, i, sizeof(edges[0]), compare);

	int* parent = (int*)malloc(sizeof(int) * VertexNum);
	for (int v = 0; v < VertexNum; v++) {
		parent[v] = -1;
	}

	i = 0;
	while (j < VertexNum - 1 && i < VertexNum * (VertexNum - 1) / 2) {
		Edge nextEdge = edges[i++];

		count++;
		//if (count > VertexNum) {
		//	break;
		//}
		int x = find(parent, nextEdge.src);
		int y = find(parent, nextEdge.dest);

		if (x != y) {
			printf(" %d", nextEdge.weight);
			totalWeight += nextEdge.weight;
			unionSubset(parent, x, y);
			j++;
		}
	}

	return totalWeight;
}

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	int vertex1, vertex2, weight;
	int totalWeight;

	scanf("%d %d", &VertexNum, &EdgeNum);

	initGraph(graph);

	for (int i = 0; i < EdgeNum; i++) {
		scanf("%d %d %d", &vertex1, &vertex2, &weight);
		insertEdge(graph, vertex1, vertex2, weight);
	}

	totalWeight = kruskalMST(graph);
	printf("\n%d", totalWeight);

}