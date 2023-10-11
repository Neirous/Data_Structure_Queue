#include <stdio.h>
#include <stdlib.h>

// ������ʽ���нṹ��
typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// ��ʼ������
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// ���
void enQueue(Queue* q, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// ����
char deQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return '\0';
    }
    char data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

// ��ӡ�����е�Ԫ��
void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    int choice;
    char name;
	fflush(stdin);
	initQueue(&q);
    do {
		printf("0.stopwork 1.queue 2.seedoctor 3.seequeue please select:");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice) {
		case 1:
			printf("������Ҫ¼����˵�������");
			scanf("%c",&name);
			enQueue(&q,name);
			fflush(stdin);
			break;
		case 2:
			name = deQueue(&q);
			if(name != '\0')
				printf("patient:%c see doctor!\n", name);
			break;
		case 3:
			printQueue(&q);
			break;
		case 0:
			exit(-1);
			break;
		}
	} while (choice != 0);
    return 0;
}

