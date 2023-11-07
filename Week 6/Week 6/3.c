#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int a = 0, b = 0, num = 0;
	int mid = 0;
	char answer = NULL;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &num);

	getchar();
	for (int i = 0; i < num; i++) {
		scanf("%c", &answer);
		mid = (a + b) / 2;
		if (answer == 'Y') {
			a = mid + 1;
		}
		else {
			b = mid;
		}
	}

	printf("%d\n", a);
}