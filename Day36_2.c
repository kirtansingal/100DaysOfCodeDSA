#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

void init(MyCircularDeque* dq, int k) {
    dq->front = 0;
    dq->rear = k - 1;
    dq->size = 0;
    dq->capacity = k;
}

bool isFull(MyCircularDeque* dq) {
    return dq->size == dq->capacity;
}

bool isEmpty(MyCircularDeque* dq) {
    return dq->size == 0;
}

bool insertFront(MyCircularDeque* dq, int value) {
    if (isFull(dq)) return false;

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = value;
    dq->size++;
    return true;
}

bool insertLast(MyCircularDeque* dq, int value) {
    if (isFull(dq)) return false;

    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = value;
    dq->size++;
    return true;
}

bool deleteFront(MyCircularDeque* dq) {
    if (isEmpty(dq)) return false;

    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return true;
}

bool deleteLast(MyCircularDeque* dq) {
    if (isEmpty(dq)) return false;

    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->size--;
    return true;
}

int getFront(MyCircularDeque* dq) {
    if (isEmpty(dq)) return -1;
    return dq->arr[dq->front];
}

int getRear(MyCircularDeque* dq) {
    if (isEmpty(dq)) return -1;
    return dq->arr[dq->rear];
}

int main() {
    MyCircularDeque dq;
    init(&dq, 3);

    insertLast(&dq, 1);
    insertLast(&dq, 2);
    insertFront(&dq, 3);
    printf("%d\n", insertFront(&dq, 4));

    printf("%d\n", getRear(&dq));
    printf("%d\n", isFull(&dq));

    deleteLast(&dq);
    insertFront(&dq, 4);

    printf("%d\n", getFront(&dq));

    return 0;
}