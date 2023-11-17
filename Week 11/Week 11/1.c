#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int visited[101] = {0, };

typedef struct Node {

	int vertex;
	struct Node* Edge;

}Node;

typedef struct Graph {

	int vertexNum;
	struct Node* adjList[101];

}Graph;

Graph* initGraph(int vertexNum) {

	Graph* graph = (Graph*)malloc(sizeof(Graph));

	graph->vertexNum = vertexNum;
	for (int i = 1; i < 102; i++) {
		graph->adjList[i] = NULL;
	}

	return graph;
}


void insertEdge(Graph* graph, int vertex1, int vertex2) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = vertex2;
	
	Node* temp = graph->adjList[vertex1];
	Node* prev = temp;
	//�ش� vertex�� ó�� ������ ������ ��
	if (temp == NULL) {
		newNode->Edge = graph->adjList[vertex1];
		graph->adjList[vertex1] = newNode;
	}
	//�ش� vertex�� �̹� ������ ������ ��
	else {
		while (1) {
			//�߰��� ���Ե� ��
			if (temp->vertex > vertex2) {
				if (temp == prev) {
					newNode->Edge = graph->adjList[vertex1];
					graph->adjList[vertex1] = newNode;
				}
				else {
					newNode->Edge = prev->Edge;
					prev->Edge = newNode;					
				}	
				break;
			}
			//�������� ���Ե� ��
			if (temp->Edge == NULL) {
				newNode->Edge = NULL;
				temp->Edge = newNode;
				break;
			}
			prev = temp;
			temp = temp->Edge;			
		}
		
	}
	

	return;
}

void DFS(Graph* graph, int vertex) {

	Node* temp;
	visited[vertex] = 1;
	printf(" %d", vertex);

	for (temp = graph->adjList[vertex]; temp; temp = temp->Edge) {
		if (!visited[temp->vertex]) {
			DFS(graph, temp->vertex);
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

	DFS(graph, searchStartVertex);

	return 0;
}
