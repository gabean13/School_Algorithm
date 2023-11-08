#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int element;
	int status;	//-2 = empty, -1 = inactive, 0 = active
}Node;

Node* Hash;
int MAX = 23;
int q = 19;
int count = 0;

int hash(int element);
int hash2(int element);
int getNextBucket(int v, int i, int element);
int insertItem(int element);
int findElement(int element);
int removeElement(int element);
void printHashTable();

int main() {
	
	char cmd = NULL;
	int element = NULL;
	int result = NULL;
	Hash = (Node*)malloc(sizeof(Node) * MAX);

	for (int i = 0; i < 23; i++) {
		Hash[i].element = 0;
		Hash[i].status = -2;	//empty
	}

	while (1) {
		scanf("%c", &cmd);
		if (cmd == 'i') {
			if (count >= MAX) {
				printf("해시테이블이 만원입니다.\n");
				continue;
			}
			scanf("%d", &element);
			if (findElement(element) != -1) {
				printf("중복된 키값입니다.\n");
				getchar();
				continue;
			}
			result = insertItem(element);
			if (result != -1) {
				printHashTable();
			}
		}
		else if (cmd == 'f') {
			scanf("%d", &element);
			result = findElement(element);
			if (result == -1) {
				printf("NoSuchKey\n");
			}
			else {
				printf("found %d\n", result);
			}
		}
		else if (cmd == 'r') {
			scanf("%d", &element);
			result = removeElement(element);
			if (result == -1) {
				printf("NoSuchKey\n");
			}
			else {
				printHashTable();
			}
		}
		else if (cmd == 'p') {
			printHashTable();
		}
		else if (cmd == 'q') {
			break;
		}
		else {
			continue;
			getchar();
		}
		getchar();
	}

	free(Hash);
	return 0;
}

int insertItem(int element) {

	int v = hash(element);
	int i = 0;

	while (i < MAX) {
		if (Hash[v].status != 0) {
			Hash[v].element = element;
			Hash[v].status = 0;
			count++;
			return 1;
		}
		else {
			v = getNextBucket(v, ++i, element);
		}
	}

	return -1;

}
int findElement(int element) {

	int v = hash(element);
	int i = 0;

	while (i < MAX) {
		if (Hash[v].status == -2) {
			return -1;
		}

		if (Hash[v].status == 0 && Hash[v].element == element) {
			return element;
		}
		else {
			v = getNextBucket(v, ++i, element);
		}
	}

	return -1;

}

int removeElement(int element) {

	int v = hash(element);
	int i = 0;

	while (i < MAX) {
		if (Hash[v].status == -2) {
			return -1;
		}

		if (Hash[v].element == element) {
			Hash[v].status = -1;
			return element;
		}
		else {
			v = getNextBucket(v, ++i, element);
		}
	}

	return -1;

}

void printHashTable() {

	for (int i = 0; i < 23; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	for (int i = 0; i < 23; i++) {
		if (Hash[i].status != 0) {
			printf("%2c ", '.');
		}
		else {
			printf("%2d ", Hash[i].element);
		}
	}
	printf("\n");
}

int hash(int element) {

	return element % MAX;

}

int hash2(int element) {

	return q - (element % q);
}

int getNextBucket(int v, int i, int element) {

	return (v + i * hash2(element) % MAX) % MAX;
}