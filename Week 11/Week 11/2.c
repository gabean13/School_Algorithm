#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Queue[101] = {0, };
int front = 0, rear = 0;
int visited[101] = { 0, };

typedef struct Graph {

	int vertexNum;
	int adjMat[101][101];

}Graph;

void enqueue(int vertex) {

	Queue[rear] = vertex;
	rear++;

}

int dequeue() {

	int value = Queue[front];
	front++;

	return value;
}

Graph* initGraph() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));

	graph->vertexNum = 100;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			graph->adjMat[i][j] = 0;
		}
	}

	return graph;
}

void insertEdge(Graph* graph, int vertex1, int vertex2) {

	graph->adjMat[vertex1][vertex2] = 1;
	graph->adjMat[vertex2][vertex1] = 1;

	return;
}

void BFS(Graph* graph, int vertex) {

	int popVertex;
	int adjVertex;

	//시작 vertex 방문처리
	visited[vertex] = 1;
	enqueue(vertex);

	while (front < rear) {
		//큐에서 제일 앞에 있는 vertex 방문처리하고 dequeue
		popVertex = dequeue();
		printf(" %d", popVertex);

		//방문처리한 vertex의 인접한 정점 검사
		for (int i = 0; i <= graph->vertexNum; i++) {
			//인접한 정점 존재할 때
			if (graph->adjMat[popVertex][i]) {		
				adjVertex = i;
				//인접한 정점을 방문하지 않았으면 방문처리하고 enqueue(하지만 dequeue되기전까지는 진짜 방문한건아님)
				if (!visited[adjVertex]) {
					visited[adjVertex] = 1;
					enqueue(adjVertex);
				}
			}
		}
	}
}

int main() {

	int vertexNum, EdgeNum, searchStartVertex;
	int vertex1, vertex2;

	scanf("%d %d %d", &vertexNum, &EdgeNum, &searchStartVertex);

	Graph* graph = initGraph(vertexNum);

	for (int i = 0; i < EdgeNum; i++) {
		scanf("%d %d", &vertex1, &vertex2);
		if (vertex1 == vertex2) {
			insertEdge(graph, vertex1, vertex2);
		}
		else {
			insertEdge(graph, vertex1, vertex2);
			insertEdge(graph, vertex2, vertex1);
		}
	}

	BFS(graph, searchStartVertex);

	return 0;
}
