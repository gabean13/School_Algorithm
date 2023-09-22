#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;	//힙의 크기(키 개수)

//비재귀 방식으로 상향식 힙 생성
void buildHeap();
//i위치에 저장된 키를 맞는 위치로 하향이동
void downHeap(int i);
//힙에 저장된 키들을 레벨순서로 출력
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

//i위치에 저장된 키를 맞는 위치로 하향이동
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
//힙에 저장된 키들을 레벨순서로 출력
void printHeap() {

	for (int i = 1; i < n + 1; i++) {
		printf(" %d", H[i]);
	}

	printf("\n");
	return;
}
