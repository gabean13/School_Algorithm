#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int vertex;
	int weight;
	struct Node* Edge;

}Node;

typedef struct Graph {
	
	int vertexNum;
	struct Node* adjList[7];

}Graph;

void initGraph(Graph* graph);
void insertVertex(Graph* graph);
void insertEdge(Graph* graph, int vertex1, int vertex2, int weight);
void printAdjList(Graph* graph, int vertex);

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	char cmd;
	int nodeNum, weight, vertex1, vertex2;

	initGraph(graph);
	for (int i = 0; i < 7; i++) {
		insertVertex(graph);
	}

	//그래프 기본구현
	insertEdge(graph, 1, 2, 1);
	insertEdge(graph, 1, 3, 1);
	insertEdge(graph, 1, 4, 1);
	insertEdge(graph, 1, 6, 2);

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

	for (int i = 0; i < 7; i++) {
		graph->adjList[i] = NULL;
	}
}

void insertVertex(Graph* graph) {

	if (graph->vertexNum > 7) {
		return;
	}
	graph->vertexNum++;
}

void insertEdge(Graph* graph, int vertex1, int vertex2, int weight) {

	if (vertex1 > 6 || vertex1 < 1 || vertex2 > 6 || vertex2 < 1) {
		printf("-1\n");
		return;
	}
	
	Node* temp;
	Node* prev;

	if (weight == 0) {
		temp = graph->adjList[vertex1];
		prev = temp;
		while (temp != NULL) {
			if (temp->vertex == vertex2) {
				if (temp == graph->adjList[vertex1]) {
					graph->adjList[vertex1] = temp->Edge;
				}
				else {
					prev->Edge = temp->Edge;
				}
				free(temp);
				break;
			}
			prev = temp;
			temp = temp->Edge;
		}
		return;
	}
	
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->vertex = vertex2;
	node1->weight = weight;
	if (graph->adjList[vertex1] == NULL) {
		node1->Edge = graph->adjList[vertex1];
		graph->adjList[vertex1] = node1;
	}
	else {
		temp = graph->adjList[vertex1]; 
		prev = temp;
		while (1) {
			//이미 해당 간선이 존재할 때
			if (temp->vertex == vertex2) {
				temp->weight = weight;
				return;
			}
			//간선이 존재하지 않고, 오름차순으로 삽입
			if (temp->vertex > vertex2) {
				if (temp == graph->adjList[vertex1]) {
					node1->Edge = graph->adjList[vertex1];
					graph->adjList[vertex1] = node1;
				}
				else {
					node1->Edge = prev->Edge;
					prev->Edge = node1;
				}	
				break;
			}
			//while문 종료
			if (temp->Edge == NULL) {
				break;
			}
			prev = temp;
			temp = temp->Edge;
		}
		//graph->adjList[vertex1]에 아무것도 없을 때
		if (temp->Edge == NULL && temp->vertex < vertex2) {
			temp->Edge = node1;
			node1->Edge = NULL;
		}	
	}
	
}

void printAdjList(Graph* graph, int vertex) {

	if (vertex > 6 || vertex < 1) {
		printf("-1\n");
		return;
	}

	Node* temp = graph->adjList[vertex];
	
	if (temp == NULL) {
		printf("-1\n");
		return;
	}

	while (temp != NULL) {
		printf(" %d %d", temp->vertex, temp->weight);
		temp = temp->Edge;
	}

	printf("\n");

	return;
}