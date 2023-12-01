#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int MAX = 30;
int H[30], A[30];

int aritelDC(int n, int start, int dest) {

	return rAritelDC(n, start, dest - 1);
}

int rAritelDC(int n, int start, int dest) {	

	if (dest == start) {
		return 0;
	}

	int cost = 0;
	int mincost = INT_MAX;

	for (int i = start; i < dest; i++) {
		cost = rAritelDC(n, start, i) + H[i] + A[dest - i];
		mincost = (mincost < cost) ? mincost : cost;
	}
	return mincost;

}

int aritelDP(int n, int start, int dest) {

	int m[30] = { 0, };
	int cost = 0;
	for (int i = start + 1; i < dest; i++) {
		m[i] = INT_MAX;
		for (int j = start; j < i; j++) {
			cost = m[j] + H[j] + A[i - j];
			m[i] = (m[i] < cost) ? m[i] : cost;
		}
	}

	return m[dest - 1];
}

int printDCValue(int n, int s, int d) {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);

	printf("%d\t %d\t %d\t ", n, s, d);
	QueryPerformanceCounter(&start);
	printf("%d\t\t DC\t\t", aritelDC(n, s, d));
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf(" %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	return 0;

}

int printDPValue(int n, int s, int d) {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);

	printf("%d\t %d\t %d\t ", n, s, d);
	QueryPerformanceCounter(&start);
	printf("%d\t\t DP\t\t", aritelDP(n, s, d));
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf(" %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	return 0;

}

int main() {

	

	int n = 0, s = 0, d = 0;

	A[0] = 0;
	A[1] = 1;

	for (int i = 2; i < MAX - 1; i++) {
		A[i] = A[i - 1] + A[i - 1] % 5 + 3;
	}

	H[0] = 1;
	H[1] = 5;

	for (int i = 2; i < MAX - 1; i++) {
		H[i] = (H[i - 1] + i) % 9 + 1;
	}

	printf("n\t s\t d\t mincost\t version\t cputime\n");

	n = 6;
	printDCValue(n, 0, 4);
	printDPValue(n, 0, 4);
	printDCValue(n, 2, 5);
	printDPValue(n, 2, 5);
	printDCValue(n, 2, 4);
	printDPValue(n, 2, 4);

	n = MAX;
	printDCValue(n, 1, 28);
	printDPValue(n, 1, 28);
}