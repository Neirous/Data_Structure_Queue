#include <stdio.h>
#include <stdlib.h>

// 定义链式队列结构体
typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// 判断队列是否为空
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// 入队
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

// 出队
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

// 打印队列中的元素
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

    // 模拟排队
    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    // 打印队列中的元素
    printQueue(&q);

    // 模拟就诊
    dequeue(&q);

    // 打印队列中的元素
    printQueue(&q);

    return 0;
}

