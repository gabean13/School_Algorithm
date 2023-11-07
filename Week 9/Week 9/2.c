#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int element;
	struct Node* next;

}Node;

void insertElement(Node* hashTable, int element);
int searchElement(Node* hashTable, int element);
int hash(int element);
int getNextBucket(int i, int element);

Node* hashTable;
int M, n;

int main() {

	int element, result;
	char order = NULL;

	scanf("%d %d", &M, &n);

	hashTable = (Node*)malloc(sizeof(Node) * M);
	for (int i = 0; i < M; i++) {
		(hashTable + i)->element = 0;
		(hashTable + i)->next = NULL;
	}

	while (1) {
		getchar();
		scanf("%c", &order);
		if (order == 'i') {
			scanf("%d", &element);
			insertElement(hashTable, element);
		}
		else if (order == 's') {
			scanf("%d", &element);
			result = searchElement(hashTable, element);
			printf("%d \n", result);
		}
		else if (order == 'e') {
			break;
		}
	}

	return 0;
}

void insertElement(Node* hashTable, int element) {

	int v = hash(element);
	int i = 1;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;

	Node* temp;
	while (1) {
		temp = hashTable + v;
		if (temp->next == NULL) {
			temp->next = newNode;
			printf("%d\n", v);
			return;
		}
		else {
			v = getNextBucket(i++, element);
			printf("C");
		}
	}

}

int searchElement(Node* hashTable, int element) {

	int i = 1;

	int v = hash(element);
	
	Node* temp;
	while (i < n) {
		temp = (hashTable + v)->next;
		if (temp == NULL) {
			break;
		}
		if (temp->element == element) {
			printf("%d ", v);
			return temp->element;
		}
		v = getNextBucket(i++, element);
	}

	return -1;
}

int hash(int element) {

	return element % M;

}

int getNextBucket(int i, int element) {
	
	return (element + i) % M;
}