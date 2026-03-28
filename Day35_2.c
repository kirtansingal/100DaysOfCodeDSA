#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

void init(MyQueue* q) {
    q->top1 = -1;
    q->top2 = -1;
}

void push(MyQueue* q, int x) {
    q->s1[++q->top1] = x;
}

void transfer(MyQueue* q) {
    if (q->top2 == -1) {
        while (q->top1 != -1) {
            q->s2[++q->top2] = q->s1[q->top1--];
        }
    }
}

int pop(MyQueue* q) {
    transfer(q);
    return q->s2[q->top2--];
}

int peek(MyQueue* q) {
    transfer(q);
    return q->s2[q->top2];
}

bool empty(MyQueue* q) {
    return (q->top1 == -1 && q->top2 == -1);
}

int main() {
    MyQueue q;
    init(&q);

    push(&q, 1);
    push(&q, 2);

    printf("%d\n", peek(&q));
    printf("%d\n", pop(&q));

    if (empty(&q)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}