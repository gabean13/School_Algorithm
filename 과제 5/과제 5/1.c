#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	INF 999999

typedef struct Node {

	int vertex;
	int weight;
	struct Node* next;

}Node;

typedef struct Graph {
	
	int vertexNum;
	int edgeNum;
	struct Node* adjlist[6];
	
}Graph;

void initGraph(Graph* graph) {

	graph->vertexNum = 6;
	graph->edgeNum = 9;
	
	for (int i = 0; i < 6; i++) {
		graph->adjlist[i] = NULL;
	}
}

void insertEdge(Graph* graph, int vertex1, int vertex2, int weight) {
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = vertex2;
	newNode->weight = weight;
	newNode->next = graph->adjlist[vertex1];
	graph->adjlist[vertex1] = newNode;

	Node* newNode2 = (Node*)malloc(sizeof(Node));
	newNode2->vertex = vertex1;
	newNode2->weight = weight;
	newNode2->next = graph->adjlist[vertex2];
	graph->adjlist[vertex2] = newNode2;

	return;
	
}

void dijkstra(Graph* graph, int start, int end) {

	int min, currentVertex;
	int num = 0;
	int dist[6];
	int path[6];
	int visited[6];
	Node* node;
	
	for (int i = 0; i < 6; i++) {
		dist[i] = INF;
		path[i] = 0;
		visited[i] = 0;
	}

	dist[start] = 0;

	while (1) {
		if (num >= 5) {
			break;
		}
		min = INF;
		for (int i = 0; i < 6; i++) {
			if (dist[i] < min && !visited[i]) {
				min = dist[i];
				currentVertex = i;
			}
		}
		visited[currentVertex] = 1;
		node = graph->adjlist[currentVertex];

		while (node != NULL) {
			if (!visited[node->vertex]) {
				if (node->weight + min == dist[node->vertex]) {
					path[node->vertex] += path[currentVertex];
				}

				if (node->weight + min < dist[node->vertex]) {
					dist[node->vertex] = node->weight + min;
					if (currentVertex == start) {
						path[node->vertex] = 1;
					}
					else {
						path[node->vertex] = path[currentVertex];
					}
				}
			}
			node = node->next;
		}
		num++;
		if (currentVertex == end) {
			break;
		}
	}

	printf("%c, %c : 최단거리 = %d, 최단경로 수 = %d\n",start + 'A', end + 'A', dist[end], path[end]);

	return;
}

int main() {

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	initGraph(graph);

	insertEdge(graph, 0, 1, 8);
	insertEdge(graph, 0, 2, 1);
	insertEdge(graph, 0, 3, 4);
	insertEdge(graph, 1, 2, 7);
	insertEdge(graph, 1, 4, 4);
	insertEdge(graph, 2, 4, 3);
	insertEdge(graph, 2, 5, 9);
	insertEdge(graph, 2, 3, 5);
	insertEdge(graph, 3, 5, 4);

	dijkstra(graph, 2, 0);
	dijkstra(graph, 2, 5);
	dijkstra(graph, 5, 2);
	dijkstra(graph, 1, 3);

	return;
}