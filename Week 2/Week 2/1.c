#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//[Week 2] 
//1. �켱���� ť - ���� ���ڸ� ����

//�ʱ⸮��Ʈ �Է�
int* insertList(int n);
//�������ڸ�����
void selectionSortList(int* list, int n);
//list���� n-1�� ���ұ��� ���Ͽ� �ִ� ���� ��ġ ��ȯ
int findMaxIndex(int* list, int n);
//����Ʈ ���
void printList(int* list, int n);


int main() {

	int* list = NULL;
	int n = 0;

	scanf("%d", &n);

	list = insertList(n);
	selectionSortList(list, n);
	printList(list, n);

	return 0;
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

void selectionSortList(int* list, int n) {

	int maxIndex;
	int temp;

	for (int i = n - 1; i > 0; i--) {
		maxIndex = findMaxIndex(list, i + 1);
		temp = list[maxIndex];
		list[maxIndex] = list[i];
		list[i] = temp;
	}

	return;
}


int findMaxIndex(int* list, int n) {
	
	int max = list[0];
	int maxIndex = 0;

	for (int i = 1; i < n; i++) {
		if (max < list[i]) {
			max = list[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

void printList(int* list, int n) {

	if (list == NULL) {
		printf("����Ʈ�� ����ֽ��ϴ�.");
		return;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d", list[i]);
	}

	printf("\n");

	return;
}