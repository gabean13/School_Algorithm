#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

//list에서 k번째 작은 원소 반환
int findKthSmallest(int* list, int n, int k);
//min~max사이의 정수 n개의 무순리스트 생성 후 반환
int* buildList(int n, int min, int max);
//list의 원소 n개를 순서대로 출력
void writeList(int* list, int n);
//list를 minHeap으로 정렬
void minHeap(int* list, int n);
//비재귀 방식으로 상향식 힙 생성
void buildHeap(int* list, int n);
//i위치에 저장된 키를 맞는 위치로 하향이동
void downHeap(int* H, int n, int i);

int main() {

	int* list;
	int* listCopy;
	int karray[4] = { 1, 100, 99900, 99999 };
	int output[4] = { 0, };
	int e = 0;

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);

	list = buildList(10, 1, 100);
	writeList(list, 10);
	for (int k = 1; k <= 3; k++) {
		output[k] = findKthSmallest(list, 10, k);
	}
	
	for (int k = 1; k <= 3; k++) {
		printf(" %d", output[k]);
	}
	printf("\n");

	list = buildList(100000, 1, 1000000);
	for (int k = 0; k <= 3; k++) {
		memcpy(listCopy, list, sizeof(list));
		QueryPerformanceCounter(&start);
		e = findKthSmallest(listCopy, 100000, karray[k]);
		QueryPerformanceCounter(&end);
		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("%d %.10f sec\n", e,((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	}
}


int findKthSmallest(int* list, int n, int k) {

	minHeap(list, n);
	return list[k - 1];

}

void minHeap(int* list, int n) {

	int temp;
	n--;

	//제일 마지막 원소를 루트 노드와 바꾼뒤 heapify진행
	while (n > 1) {
		buildHeap(list, n);
		temp = list[n];
		list[n] = list[0];
		list[0] = temp;
		n--;
	}
}

void buildHeap(int *list, int n) {

	for (int i = n / 2 - 1; i >= 0; i--) {
		downHeap(list, n, i);
	}
}

void downHeap(int *H, int n, int i) {

	int leftChild = i * 2 + 1;
	int rightChild = i * 2 + 2;
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
		downHeap(H, n, rightChild);
	}
	//3-3. 왼쪽 자식만 큼
	else if (H[i] < H[leftChild] && H[i] >= H[rightChild]) {
		temp = H[i];
		H[i] = H[leftChild];
		H[leftChild] = temp;
		downHeap(H, n, leftChild);
	}
	//3-4. 자식 둘다 큼
	else {
		//더 큰 애랑 바꿔줌
		if (H[leftChild] > H[rightChild]) {
			temp = H[i];
			H[i] = H[leftChild];
			H[leftChild] = temp;
			downHeap(H, n, leftChild);
		}
		else {
			temp = H[i];
			H[i] = H[rightChild];
			H[rightChild] = temp;
			downHeap(H, n, rightChild);
		}
	}
}

int* buildList(int n, int min, int max) {

	int randomNum = 0;
	int* list = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		randomNum = rand() % (max - min + 1) + min;
		list[i] = randomNum;
	}

	return list;
}

void writeList(int* list, int n) {

	for (int i = 0; i < n; i++) {
		printf(" %d", list[i]);
	}
	printf("\n");

	return;
}