#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;	//힙의 키 개수

//무순배열을 제자리 힙 정렬
void inPlaceHeapSort();
//힙 H 순서대로 출력
void printArray();
//n위치에 key삽입
void insertItem(int key);
//i위치에 저장된 키를 맞는 위치로 상향이동
void upHeap(int i);
//i위치에 저장된 키를 맞는 위치로 하향이동
void downHeap(int i);
//비재귀 방식으로 상향식 힙 생성
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

	//제일 마지막 원소를 루트 노드와 바꾼뒤 heapify진행
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

	//1. 자식이 둘다 없음
	if (leftChild > n) {
		return;
	}

	//2. 자식이 왼쪽 하나만 있음
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


	//3. 자식이 둘다 있음
	//3-1. 자식 둘다 작음
	if (H[i] >= H[leftChild] && H[i] >= H[rightChild]) {
		return;
	}
	//3-2. 오른쪽 자식만 큼
	else if (H[i] < H[rightChild] && H[i] >= H[leftChild]) {
		temp = H[i];
		H[i] = H[rightChild];
		H[rightChild] = temp;
		downHeap(rightChild);
	}
	//3-3. 왼쪽 자식만 큼
	else if (H[i] < H[leftChild] && H[i] >= H[rightChild]) {
		temp = H[i];
		H[i] = H[leftChild];
		H[leftChild] = temp;
		downHeap(leftChild);
	}
	//3-4. 자식 둘다 큼
	else {
		//더 큰 애랑 바꿔줌
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
