#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	char element;
	struct Node* prev, *next;
}Node;

int n;		// 원소 개수

int add(Node* list, int rank, char element);

int main() {

	Node *head = (Node*)malloc(sizeof(Node));
	head->prev = NULL;
	head->next = NULL;

	int orderNum, rank;
	char order, element;

	scanf("%d", &orderNum);

	for (int i = 0; i < orderNum; i++) {
		scanf("%c", &order);
		if (order == 'A') {
			scanf("%d %c", &rank, &element);
			if (add(head, rank, element) == -1) {
				i--;
			}
		}
		else if (order == 'D') {

		}
		else if (order == 'G') {

		}
		else if (order == 'P') {

		}
	}
}

int add(Node* list, int rank, char element) {
	
	if (rank < 1 || rank > n + 1) {
		printf("invalid position \n");
		return -1;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;

	

	

}