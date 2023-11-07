#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

int n = 10000;
int Limits[4] = { 1, 100, 500, 1000 };
int Limit, Mode;

//배열 생성
int* createArray();
int* quickSort(int* A);
int* rQuickSort(int* A, int l, int r);
int findPivot(int* A, int l, int r);
int findIndexOfMedianOfThree(int* A, int a, int b, int c);
void inPlacePartiton(int* A, int l, int r, int k, int *a, int* b);
void insertionSort(int *A, int n);

int main() {
	
	int* A;
	int Acopy[100000] = { 0, };
	int mode[4] = { 1, 3, 11, 13 };
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);

	A = createArray();

	printf("Limits\t 결정적1\t 결정적3\t 무작위1\t 무작위3 \n");
	for (int i = 0; i < 4; i++) {
		Limit = Limits[i];
		printf("%d\t", Limit);
		for (int j = 0; j < 4; j++) {
			Mode = mode[j];
			memcpy(Acopy, A, n);
			QueryPerformanceCounter(&start);
			quickSort(Acopy, n);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("%.8f\t", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
		}
		printf("\n");
	}

}

int* createArray() {

	int* A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		A[i] = rand() % n + 1;
	}

	return A;
}

int* quickSort(int* A) {

	rQuickSort(A, 0, n - 1);
	if (Limit > 1) {
		insertionSort(A, n);
	}
	return;
}

void insertionSort(int* A, int n) {

	int temp;
	int j;

	for (int i = 0; i < n - 1; i++) {
		j = i;
		while (j >= 0 && A[j] > A[j + 1]) {
			temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			j--;
		}
	}
}

int* rQuickSort(int* A, int l, int r) {

	int k;
	int a = 0, b = 0;

	if (r - l >= Limit) {
		k = findPivot(A, l, r);
		inPlacePartiton(A, l, r, k, &a, &b);
		rQuickSort(A, l, a - 1);
		rQuickSort(A, b + 1, r);
	}
}

void inPlacePartiton(int* A, int l, int r, int k, int* a, int* b) {

	int pivot = A[k];
	int i = l,lt = l,gt = r;
	int temp;

	while (i <= gt) {
		if (pivot == A[i]) {
			i++;
		}
		else if (A[i] < pivot) {
			temp = A[lt];
			A[lt] = A[i];
			A[i] = temp;
			lt++;
			i++;
		}
		else if (A[i] > pivot) {
			temp = A[gt];
			A[gt] = A[i];
			A[i] = temp;
			gt--;
		}
	}

	*a = lt;
	*b = gt;
}

int findPivot(int* A, int l, int r) {

	int a = 0, b = 0, c= 0;

	if (Mode == 1) {
		return r;
	}
	if (Mode == 11) {
		return rand() % (r - l + 1) + l;
	}
	if (r - l == 1) {
		return l;
	}
	switch (Mode) {
	case 3:
		a = l;
		b = (l + r) / 2;
		c = r;
	case 13:
		a = rand() % (r - l + 1) + l;
		b = rand() % (r - l + 1) + l;
		c = rand() % (r - l + 1) + l;
	}
	return findIndexOfMedianOfThree(A, a, b, c);
}

int findIndexOfMedianOfThree(int* A, int a, int b, int c) {

	if (A[a] >= A[b]) {
		if (A[b] >= A[c]) {
			return b;		// a > b > c
		}
		else if (A[c] >= A[a]) {
			return a;		// c > a > b
		}
		else {
			return c;		// a > c > b
		}
	}
	else if (A[b] >= A[a]) {
		if (A[a] >= A[c]) {
			return a;		// b > a > c
		}
		else if (A[c] >= A[b]) {
			return b;		// c > b > a
		}
		else {
			return c;		// b > c > a
		}
	}
}
