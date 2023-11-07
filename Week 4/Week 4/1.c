#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;	//���� Ű ����

//�����迭�� ���ڸ� �� ����
void inPlaceHeapSort();
//�� H ������� ���
void printArray();
//n��ġ�� key����
void insertItem(int key);
//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
void upHeap(int i);
//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
void downHeap(int i);
//����� ������� ����� �� ����
void buildHeap();

int main() {

	int element = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}

	inPlaceHeapSort();

	printArray();
}

void inPlaceHeapSort() {
	buildHeap();

	int temp;
	int num = n;

	//���� ������ ���Ҹ� ��Ʈ ���� �ٲ۵� heapify����
	for (int i = n; i > 1; i--) {
		temp = H[1];
		H[1] = H[i];
		H[i] = temp;

		n--;

		downHeap(1);
	}

	n = num;

}

void printArray() {

	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");

	return;
}

void insertItem(int key) {

	n++;
	H[n] = key;
	upHeap(n);
	printf("0 \n");
	return;

}

void upHeap(int i) {

	int parentIndex = i / 2;
	int temp = 0;

	while (H[i] >= H[parentIndex] && parentIndex >= 1) {
		temp = H[i];
		H[i] = H[parentIndex];
		H[parentIndex] = temp;
		i = parentIndex;
		parentIndex /= 2;
	}
}


void downHeap(int i) {

	int leftChild = i * 2;
	int rightChild = i * 2 + 1;
	int temp;

	//1. �ڽ��� �Ѵ� ����
	if (leftChild > n) {
		return;
	}

	//2. �ڽ��� ���� �ϳ��� ����
	if (rightChild > n) {
		if (H[i] < H[leftChild]) {
			temp = H[i];
			H[i] = H[leftChild];
			H[leftChild] = temp;
			return;
		}
		else {
			return;
		}
	}


	//3. �ڽ��� �Ѵ� ����
	//3-1. �ڽ� �Ѵ� ����
	if (H[i] >= H[leftChild] && H[i] >= H[rightChild]) {
		return;
	}
	//3-2. ������ �ڽĸ� ŭ
	else if (H[i] < H[rightChild] && H[i] >= H[leftChild]) {
		temp = H[i];
		H[i] = H[rightChild];
		H[rightChild] = temp;
		downHeap(rightChild);
	}
	//3-3. ���� �ڽĸ� ŭ
	else if (H[i] < H[leftChild] && H[i] >= H[rightChild]) {
		temp = H[i];
		H[i] = H[leftChild];
		H[leftChild] = temp;
		downHeap(leftChild);
	}
	//3-4. �ڽ� �Ѵ� ŭ
	else {
		//�� ū �ֶ� �ٲ���
		if (H[leftChild] > H[rightChild]) {
			temp = H[i];
			H[i] = H[leftChild];
			H[leftChild] = temp;
			downHeap(leftChild);
		}
		else {
			temp = H[i];
			H[i] = H[rightChild];
			H[rightChild] = temp;
			downHeap(rightChild);
		}
	}
}
void buildHeap() {

	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}
