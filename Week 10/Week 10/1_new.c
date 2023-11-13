#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int vertex;
	int weight;
	struct Node* Next;

}Node;

typedef struct Graph {

	int vertexNum;
	struct Node* adjList[7];

}Graph;

void initGraph(Graph* graph);
void insertEdge(Graph* graph, int vertex1, int vertex2, int weight);
void printAdjList(Graph* graph, int vertex);

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	char cmd;
	int nodeNum, weight, vertex1, vertex2;

	initGraph(graph);
	//그래프 기본구현
	insertEdge(graph, 1, 2, 1);
	insertEdge(graph, 1, 3, 1);
	insertEdge(graph, 1, 6, 2);
	insertEdge(graph, 1, 4, 1);

	insertEdge(graph, 2, 1, 1);
	insertEdge(graph, 2, 3, 1);

	insertEdge(graph, 3, 1, 1);
	insertEdge(graph, 3, 2, 1);
	insertEdge(graph, 3, 5, 4);

	insertEdge(graph, 4, 1, 1);

	insertEdge(graph, 5, 3, 4);
	insertEdge(graph, 5, 5, 4);
	insertEdge(graph, 5, 6, 3);

	insertEdge(graph, 6, 1, 2);
	insertEdge(graph, 6, 5, 3);

	while (1) {
		scanf("%c", &cmd);
		if (cmd == 'a') {
			scanf("%d", &nodeNum);
			printAdjList(graph, nodeNum);
		}
		else if (cmd == 'm') {
			scanf("%d %d %d", &vertex1, &vertex2, &weight);
			if (vertex1 == vertex2) {
				insertEdge(graph, vertex1, vertex2, weight);
			}
			else {
				insertEdge(graph, vertex1, vertex2, weight);
				insertEdge(graph, vertex2, vertex1, weight);
			}
		}
		else if (cmd == 'q') {
			break;
		}
		getchar();
	}

	return;
}

void initGraph(Graph* graph) {
	graph->vertexNum = 0;

	for (int i = 0; i < 6; i++) {
		graph->adjList[i] = i;
	}
}


void insertEdge(Graph* graph, int vertex1, int vertex2, int weight) {

	vertex1--;
	vertex2--;
	if (vertex1 > 5 || vertex1 < 0 || vertex2 > 5 || vertex2 < 0) {
		printf("-1\n");
		return;
	}

	Node* temp = graph->adjList[vertex1];

	//간선이 존재하는 경우
	while (temp != NULL) {
		if (temp->vertex == vertex2) {
			temp->weight = weight;
			return;
		}
		temp = temp->Next;
	}

	//간선이 존재하지 않는 경우
	temp = graph->adjList[vertex1];
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = vertex2;
	newNode->weight = weight;
	newNode->Next = NULL;

	//첫번째로 삽입하는 경우
	if (temp == NULL) {
		graph->adjList[vertex1] = newNode;
		return;
	}

	//오름차순으로 삽입하기 위함
	Node* prev = temp;
	while (1) {
		if (prev->vertex > vertex2) {
			newNode->Next = prev->Next;
			prev->Next = newNode;
		}
		if (temp == NULL) {
			prev->Next = newNode;
			break;
		}
		prev = temp;
		temp = temp->Next;
	}


	return;

}

void printAdjList(Graph* graph, int vertex) {

	vertex--;
	if (vertex > 5 || vertex < 0) {
		printf("-1\n");
		return;
	}

	Node* temp = graph->adjList[vertex];
	while (temp != NULL) {
		if (temp->weight == 0) {
			temp = temp->Next;
		}
		printf(" %d %d", temp->vertex + 1, temp->weight);
		temp = temp->Next;
	}
	printf("\n");

	return;
}