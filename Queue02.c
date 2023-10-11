#include <stdio.h>
#include <stdlib.h>

// ����ѭ�����нṹ��
typedef struct Queue {
    char* data;
    int front;
    int rear;
    int size;
} Queue;

// ��ʼ������
void initQueue(Queue* q, int size) {
    q->data = (char*)malloc(sizeof(char) * (size+1));
    q->front = q->rear = 0;
    q->size = ++size;
}

// �ж϶����Ƿ�Ϊ��
int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// �ж϶����Ƿ�����
int isQueueFull(Queue* q) {
    return (q->rear + 1) % q->size == q->front;
}

// ���
void enqueue(Queue* q, char data) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % q->size;
}

// ����
char dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return '\0';
    }
    char data = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return data;
}

// ��ӡ�����е�Ԫ��
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
    printf("���������������");
	scanf("%d",&num); 
	fflush(stdin);
	initQueue(&q, num);
    do {
		printf("0.stopwork 1.queue 2.seedoctor 3.seequeue please select:");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice) {
		case 1:
			printf("������Ҫ¼����˵�������");
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

