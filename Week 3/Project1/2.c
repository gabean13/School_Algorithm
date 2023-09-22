#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;	//���� ũ��(Ű ����)

//����� ������� ����� �� ����
void buildHeap();
//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
void downHeap(int i);
//���� ����� Ű���� ���������� ���
void printHeap();
int main() {
	
	int keyCount = 0;
	
	scanf("%d", &keyCount);
	n = keyCount;

	for (int i = 1; i <= keyCount; i++) {
		scanf("%d", &H[i]);
	}

	buildHeap();
	printHeap();
}

void buildHeap() {

	for (int i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}

//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
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
//���� ����� Ű���� ���������� ���
void printHeap() {

	for (int i = 1; i < n + 1; i++) {
		printf(" %d", H[i]);
	}

	printf("\n");
	return;
}
