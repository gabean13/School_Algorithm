#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//[Week 2] 
//2. 우선순위 큐 - 삽입 제자리 정렬

//초기리스트 입력
int* insertList(int n);
//제자리 삽입 정렬
void sortListToInsertList(int* list, int n);
//리스트 출력
void printList(int* list, int n);


int main() {

	int* list = NULL;
	int n = 0;

	scanf("%d", &n);

	list = insertList(n);
	sortListToInsertList(list, n);
	printList(list, n);

	return 0;
}

void sortListToInsertList(int* list, int n) {
	
	int biggerIndex;
	int temp;

	for (int i = 1; i < n; i++) {
		temp = list[i];
		//i번째 원소가 들어갈 위치 찾기(원소보다 큰 값이 있는 곳)
		biggerIndex = i;
		for (int j = 0; j < i; j++) {
			if (list[j] > temp) {
				biggerIndex = j;
				break;
			}
		}
		for (int j = i; j > biggerIndex; j--) {
			list[j] = list[j - 1];
		}
		list[biggerIndex] = temp;
	}
}

int* insertList(int n) {

	int element;
	int* list = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &element);
		list[i] = element;
	}

	return list;
}



void printList(int* list, int n) {

	if (list == NULL) {
		printf("리스트가 비어있습니다.");
		return;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d", list[i]);
	}

	printf("\n");

	return;
}