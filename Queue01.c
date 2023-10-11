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
void enqueue(Queue* q, char data) {
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
char dequeue(Queue* q) {
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
    initQueue(&q);

    // ģ���Ŷ�
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    // ��ӡ�����е�Ԫ��
    printQueue(&q);

    // ģ�����
    dequeue(&q);

    // ��ӡ�����е�Ԫ��
    printQueue(&q);

    return 0;
}

