#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;	//���� ũ��(Ű ����)

//n��ġ�� key����
void insertItem(int key);
//��Ʈ Ű ���� �� ��ȯ
int removeMax();
//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
void upHeap(int i);
//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
void downHeap(int i);
//���� ����� Ű���� ���������� ���
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

//n��ġ�� key����
void insertItem(int key) {

	n++;
	H[n] = key;
	upHeap(n);
	printf("0 \n");
	return;

}

//��Ʈ Ű ���� �� ��ȯ
int removeMax() {

	int key = H[1];

	H[1] = H[n];
	H[n] = 0;
	n--;
	downHeap(1);
	return key;
}

//i��ġ�� ����� Ű�� �´� ��ġ�� �����̵�
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
	else if(H[i] < H[rightChild] && H[i] >= H[leftChild]){
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
