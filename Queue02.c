#include <stdio.h>
#include <stdlib.h>

// 定义循环队列结构体
typedef struct Queue {
    char* data;
    int front;
    int rear;
    int size;
} Queue;

// 初始化队列
void initQueue(Queue* q, int size) {
    q->data = (char*)malloc(sizeof(char) * (size+1));
    q->front = q->rear = 0;
    q->size = ++size;
}

// 判断队列是否为空
int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// 判断队列是否已满
int isQueueFull(Queue* q) {
    return (q->rear + 1) % q->size == q->front;
}

// 入队
void enqueue(Queue* q, char data) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % q->size;
}

// 出队
char dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return '\0';
    }
    char data = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return data;
}

// 打印队列中的元素
void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%c ", q->data[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    Queue q;
    int choice;
    int num;
    char name;
    printf("请输入最大人数：");
	scanf("%d",&num); 
	fflush(stdin);
	initQueue(&q, num);
    do {
		printf("0.stopwork 1.queue 2.seedoctor 3.seequeue please select:");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice) {
		case 1:
			printf("请输入要录入的人的姓名：");
			scanf("%s",&name);
			enqueue(&q,name);
			fflush(stdin);
			break;
		case 2:
			name = dequeue(&q);
			printf("patient:%c see doctor!", name);
			break;
		case 3:
			printQueue(&q);
			break;
		case 0:
			exit(-1);
			break;
		}
	} while (choice != 0);
    

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

