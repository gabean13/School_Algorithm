#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int element;
	struct Node* next;

}Node;

//���ο� ��带 ����Ʈ �������� �߰�
Node* newNode(Node* head, int element); 
//����Ʈ ��ü ���
void printNode(Node* head);

int main() {

	int n = 0;
	int element = 0;
	Node* head = NULL;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &element);
		newNode(&head, element);
	}
	printNode(&head);
}

Node* newNode(Node** head, int element) {
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = element;
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
	}
	else {
		Node* temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void printNode(Node** head) {

	Node* temp = *head;

	while (temp != NULL) {
		printf(" %d", temp->element);
		temp = temp->next;
	}
	printf("\n");

	return;
}