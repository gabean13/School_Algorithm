#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findElement(int* list, int k, int n);
int rFindElement(int* list, int k, int l, int r);

int main() {

	int n = 0, k = 0;
	int index = 0;
	int* list;

	scanf("%d", &n);
	scanf("%d", &k);
	list = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	index = findElement(list, k, n);
	if (list[index] > k) {
		printf(" -1\n");
	}
	else {
		printf(" %d\n", index);
	}

	free(list);
	return 0;
}

int findElement(int* list, int k, int n) {

	return rFindElement(list, k, 0, n - 1);
}

int rFindElement(int* list, int k, int l, int r) {

	//해당 키가 리스트에 존재하지 않음
	int mid = (l + r) / 2;

	if (l > r) {
		return mid;
	}

	if (k == list[mid]) {
		return mid;
	}
	else if(k < list[mid]) {
		return rFindElement(list, k, l, mid - 1);
	}
	else {
		return rFindElement(list, k, mid + 1, r);
	}

}