#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int element;
	struct Node* next;

}Node;

void insertElement(int element);
int searchElement(int element);
void printHashTable();
int hash(int element);
int hash2(int element);
int getNextBucket(int v, int i, int element);

int* hashTable;
int M, n, q;

int main() {

	int element, result;
	char order = NULL;

	scanf("%d %d %d", &M, &n, &q);

	hashTable = (int*)malloc(sizeof(int) * M);
	for (int i = 0; i < M; i++) {
		hashTable[i] = 0;
	}

	while (1) {
		getchar();
		scanf("%c", &order);
		if (order == 'i') {
			scanf("%d", &element);
			insertElement(element);
		}
		else if (order == 's') {
			scanf("%d", &element);
			result = searchElement(element);
			printf("%d \n", result);
		}
		else if (order == 'p') {
			printHashTable();
		}
		else if (order == 'e') {
			printHashTable();
			break;
		}
	}

	return 0;
}

void insertElement(int element) {

	int v = hash(element);
	int i = 0, index;

	while (1) {
		index = getNextBucket(v, i++, element);
		if (hashTable[index] == 0) {
			hashTable[index] = element;
			printf("%d \n", index);
			return;
		}
		else {
			printf("C");
		}
	}

}

int searchElement(int element) {

	int i = 0, index;
	int v = hash(element);

	Node* temp;
	while (i < n) {
		index = getNextBucket(v, i++, element);
		if (hashTable[index] == element) {
			printf("%d ", index);
			return element;
		}
		else if (hashTable[index] == 0) {
			return -1;
		}
	}

	return -1;
}

void printHashTable() {

	for (int i = 0; i < M; i++) {
		printf(" %d", hashTable[i]);
	}

	printf("\n");
	return;
}

int hash(int element) {

	return element % M;

}

int hash2(int element) {

	return q - (element % q);
}

int getNextBucket(int v, int i, int element) {

	return (v + i * hash2(element) % M ) % M;
}