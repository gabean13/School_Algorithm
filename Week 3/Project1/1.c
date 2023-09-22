#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;	//힙의 크기(키 개수)

//n위치에 key삽입
void insertItem(int key);
//루트 키 삭제 후 반환
int removeMax();
//i위치에 저장된 키를 맞는 위치로 상향이동
void upHeap(int i);
//i위치에 저장된 키를 맞는 위치로 하향이동
void downHeap(int i);
//힙에 저장된 키들을 레벨순서로 출력
void printHeap();


int main() {
	
	char order = NULL;
	int key = 0;
	int deleteKey = 0;

	while(1) {
		scanf("%c", &order);;
		if (order == 'i') {
			scanf("%d", &key);
			insertItem(key);
		}
		else if (order == 'd') {
			deleteKey = removeMax();
			printf("%d \n", deleteKey);
		}
		else if (order == 'p') {
			printHeap();
		}
		else if(order == 'q') {
			break;
		}
		getchar();
	} 

}

//n위치에 key삽입
void insertItem(int key) {

	n++;
	H[n] = key;
	upHeap(n);
	printf("0 \n");
	return;

}

//루트 키 삭제 후 반환
int removeMax() {

	int key = H[1];

	H[1] = H[n];
	H[n] = 0;
	n--;
	downHeap(1);
	return key;
}

//i위치에 저장된 키를 맞는 위치로 상향이동
void upHeap(int i) {
	
	int parentIndex = i / 2;
	int temp  = 0;

	while (H[i] >= H[parentIndex] && parentIndex >= 1) {
		temp = H[i];
		H[i] = H[parentIndex];
		H[parentIndex] = temp;
		i = parentIndex;
		parentIndex /= 2;
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
	else if(H[i] < H[rightChild] && H[i] >= H[leftChild]){
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
