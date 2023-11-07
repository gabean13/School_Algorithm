#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findElement(int* list, int k, int n);

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

	if (list[index] < k) {
		printf(" %d\n", n);
	}
	else {
		printf(" %d\n", index);
	}

	free(list);
	return 0;
}

int findElement(int* list, int k, int n) {

	int left = 0, right = n - 1;
	int mid = 0;

	while (1) {
		mid = (left + right) / 2;
		if (left > right) {
			return right + 1;
		}
		if (k == list[mid]) {
			return mid;
		}
		else if (k < list[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}
}