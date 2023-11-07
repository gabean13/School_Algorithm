#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int element;
	struct Node* next;

}Node;

Node* hashTable;
int M;

void insertElement(Node* hashTable, int element);
int searchElement(Node* hashTable, int element);
int deleteElement(Node* hashTable, int element);
void printHashTable(Node* hashTable);
int hash(int element);

int main() {

	int element, result;
	char order = NULL;

	scanf("%d", &M);

	hashTable = (Node*)malloc(sizeof(Node) * M);
	for (int i = 0; i < M; i++) {
		(hashTable + i)->element = NULL;
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
		else if (order == 'd') {
			scanf("%d", &element);
			result = deleteElement(hashTable, element);
			printf("%d \n", result);
		}
		else if (order == 'p') {
			printHashTable(hashTable);
		}
		else if (order == 'e') {
			break;
		}
	}

	return 0;
}

void insertElement(Node* hashTable, int element) {
	
	int v = hash(element);

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;

	Node* temp = hashTable + v;
	if (temp->next == NULL) {
		temp->next = newNode;
	}
	else {
		newNode->next = temp->next;
		temp->next = newNode;
	}

}

int searchElement(Node* hashTable, int element) {

	int v = hash(element);
	int index = 0;
	Node* temp = hashTable + v;

	while (1) {
		if (temp->element == element) {
			return index;
		}
		else {
			if (temp->next == NULL) {
				break;
			}
			temp = temp->next;
			index++;
		}
		
	}

	return 0;
}

int deleteElement(Node* hashTable, int element) {

	int index = 0;
	int v = hash(element);
	Node* temp = hashTable + v;
	Node* temp2 = hashTable + v;

	while (temp->next != NULL) {
		index++;
		temp = temp->next;
		if (temp->element == element) {
			while (temp2->next != temp) {
				temp2 = temp2->next;
			}
			temp2->next = temp->next;
			return index;
		}
	}
	

	return 0;
}

void printHashTable(Node* hashTable) {

	Node* temp = hashTable;

	for (int i = 0; i < M; i++) {
		temp = (hashTable + i);
		while (temp->next != NULL) {
			temp = temp->next;
			printf(" %d", temp->element);
		}
	}

	printf("\n");
	return;
}

int hash(int element) {

	return element % M;

}