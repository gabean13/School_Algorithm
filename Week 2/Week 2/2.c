#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//[Week 2] 
//2. �켱���� ť - ���� ���ڸ� ����

//�ʱ⸮��Ʈ �Է�
int* insertList(int n);
//���ڸ� ���� ����
void sortListToInsertList(int* list, int n);
//����Ʈ ���
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
		//i��° ���Ұ� �� ��ġ ã��(���Һ��� ū ���� �ִ� ��)
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
		printf("����Ʈ�� ����ֽ��ϴ�.");
		return;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d", list[i]);
	}

	printf("\n");

	return;
}