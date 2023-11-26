#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	char vertex;
	struct node* next;

}node;

typedef struct diretedGraph {

	int vertexNum;
	struct node* adjlist[1000];

}diretedGraph;

diretedGraph* DiretedGraph;
int VertexNum, EdgeNum;
int* Indegree;
int* Queue;
int front, rear;

void initGraph() {

	DiretedGraph = (diretedGraph*)malloc(sizeof(diretedGraph));

	DiretedGraph->vertexNum = 0;

	Indegree = (int*)malloc(sizeof(int) * (1000));
	for (int i = 0; i < 1000; i++) {
		DiretedGraph->adjlist[i] = NULL;
		Indegree[i] = 0;
	}

}

int returnIndex(char vName) {

	return vName - 'A';

}

void insertVertex(char vName, int i) {

	DiretedGraph->vertexNum++;

}

void insertDiretedEdge(char uName, char wName) {

	node* newNode = (node*)malloc(sizeof(node));

	newNode->vertex = wName;
	newNode->next = DiretedGraph->adjlist[returnIndex(uName)];

	DiretedGraph->adjlist[returnIndex(uName)] = newNode;

	Indegree[returnIndex(wName)]++;

	return;
}

void buildGraph() {

	char vertexName;
	char uName, wName;
	
	scanf("%d", &VertexNum);
	
	initGraph();
	for (int i = 0; i < VertexNum; i++) {
		getchar();
		scanf("%c", &vertexName);
		insertVertex(vertexName, i);
	}

	scanf("%d", &EdgeNum);

	for (int i = 0; i < EdgeNum; i++) {
		getchar();
		scanf("%c %c", &uName, &wName);
		insertDiretedEdge(uName, wName);
	}

	return;

}

int isEmpty() {

	return front == rear;
}

void initQueue() {

	Queue = (int*)malloc(sizeof(int) * 1000);
	front = 0;
	rear = 0;

}

void enqueue(int vertex) {

	Queue[rear] = vertex;
	rear++;

}

int dequeue() {

	return Queue[front++];

}

char* topologicalSort() {

	int count = 0;
	int dequeueIndex;
	int intTemp;
	int index = 0;
	node* temp = NULL;
	char* T = (char*)malloc(sizeof(char) * VertexNum);

	initQueue();

	for (int i = 0; i < VertexNum; i++) {
		if (Indegree[i] == 0) {
			enqueue(i);
		}
	}

	while (!isEmpty()) {
		dequeueIndex = dequeue();

		T[index++] = dequeueIndex + 'A';
		count++;

		temp = DiretedGraph->adjlist[dequeueIndex];
		while (temp != NULL) {
			intTemp = returnIndex(temp->vertex);
			Indegree[intTemp]--;

			if (Indegree[intTemp] == 0) {
				enqueue(intTemp);
			}
			temp = temp->next;
		}
	}

	if (count != VertexNum) {
		return NULL;
	}

	return T;

}

int main() {

	char* T;

	buildGraph();
	T = topologicalSort();
	if (T == NULL) {
		printf("0");
	}
	else {
		for (int i = 0; i < VertexNum; i++) {
			printf("%c ", T[i]);
		}
	}
	
	printf("\n");
	free(Queue);

	return 0;
}