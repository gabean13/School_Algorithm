#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* lChild;
	struct node* rChild;
	int key;

}node;

node* root = NULL;

node* findElement(node* v, int key);
node* insertItem(node* v, int key);
node* treeSearch(node* v, int key);
node* removeElement(node* v, int key);
node* minValue(node* v);
int isExternal(node* w);
int isInternal(node* w);
void preOrder(node* v);

int main() {

	char order = NULL;
	int key = 0;
	int result = 0;
	node* temp;

	while (1) {
		scanf("%c", &order);
		if (order == 'q') {
			break;
		}
		else if (order == 'i') {
			scanf("%d", &key);
			root = insertItem(root, key);
		}
		else if (order == 'd') {
			scanf("%d", &key);
			temp = findElement(root, key);
			removeElement(root, key);
			if (temp == NULL) {
				printf("X \n");
			}
			else {
				printf("%d \n", key);
			}
		}
		else if (order == 's') {
			scanf("%d", &key);
			temp = findElement(root, key);
			if (temp == NULL) {
				printf("X\n");
			}
			else {
				printf("%d \n", temp->key);
			}
		}
		else if (order == 'p') {
			preOrder(root);
			printf("\n");
		}
		else {
			continue;
		}
		getchar();
	}
}

int isExternal(node* w) {
	if (w->rChild == NULL && w->lChild == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

int isInternal(node* w) {
	if (w->lChild != NULL || w->rChild != NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

node* insertItem(node* v, int key) {	

	if (v == NULL) {
		v = (node*)malloc(sizeof(node));
		v->key = key;
		v->lChild = NULL;
		v->rChild = NULL;
		return v;

	}
	else {
		if (key < v->key) {
			v->lChild = insertItem(v->lChild, key);
		}
		else {
			v->rChild = insertItem(v->rChild, key);
		}
	}
	return v;
}

node* findElement(node*v, int key) {

	if (v == NULL) {
		return NULL;
	}
	
	if (v->key == key) {
		return v;
	}
	else if (key < v->key) {
		return findElement(v->lChild, key);
	}
	else {
		return findElement(v->rChild, key);
	}
}

node* treeSearch(node* v, int key) {

	if (isExternal(v)) {
		return v;
	}
	if (key == v->key) {
		return v;
	}
	else if (key < v->key) {
		return treeSearch(v->lChild, key);
	}
	else if (key > v->key) {
		return treeSearch(v->rChild, key);
	}

}

void preOrder(node* v) {
	if (v != NULL) {
		printf(" %d", v->key);
		preOrder(v->lChild);
		preOrder(v->rChild);
	}
}

node* removeElement(node* v, int key) {

	node* temp;

	if (v == NULL)
		return v;

	if (key < v->key)
		v->lChild = removeElement(v->lChild, key);

	else if (key > v->key)
		v->rChild = removeElement(v->rChild, key);

	else {
		if (v->lChild == NULL) {
			temp = v->rChild;
			free(v);
			return temp;
		}
		else if (v->rChild == NULL) {
			temp = v->lChild;
			free(v);
			return temp;
		}

		temp = minValue(v->rChild);
		v->key = temp->key;
		v->rChild = removeElement(v->rChild, temp->key);
	}
	return v;
}

node* minValue(node* v) {

	node* temp = v;

	while (temp && temp->lChild != NULL) {
		temp = temp->lChild;
	}

	return temp;
}