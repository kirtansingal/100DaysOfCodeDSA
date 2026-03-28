#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void init(struct Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
}

void push_front(struct Deque* dq, int val) {
    struct Node* node = createNode(val);
    if (dq->front == NULL) {
        dq->front = dq->rear = node;
    } else {
        node->next = dq->front;
        dq->front->prev = node;
        dq->front = node;
    }
    dq->size++;
}

void push_back(struct Deque* dq, int val) {
    struct Node* node = createNode(val);
    if (dq->rear == NULL) {
        dq->front = dq->rear = node;
    } else {
        node->prev = dq->rear;
        dq->rear->next = node;
        dq->rear = node;
    }
    dq->size++;
}

void pop_front(struct Deque* dq) {
    if (dq->front == NULL) return;

    struct Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL;
    }

    free(temp);
    dq->size--;
}

void pop_back(struct Deque* dq) {
    if (dq->rear == NULL) return;

    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL;
    }

    free(temp);
    dq->size--;
}

int front(struct Deque* dq) {
    if (dq->front == NULL) return -1;
    return dq->front->data;
}

int back(struct Deque* dq) {
    if (dq->rear == NULL) return -1;
    return dq->rear->data;
}

int empty(struct Deque* dq) {
    return dq->size == 0;
}

int size(struct Deque* dq) {
    return dq->size;
}

void clear(struct Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void display(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Deque dq;
    init(&dq);

    push_back(&dq, 10);
    push_front(&dq, 5);
    push_back(&dq, 20);
    push_front(&dq, 1);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    pop_front(&dq);
    pop_back(&dq);

    display(&dq);

    clear(&dq);

    return 0;
}