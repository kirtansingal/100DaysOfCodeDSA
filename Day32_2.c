#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int minData[MAX];
    int top;
} MinStack;

void init(MinStack* s) {
    s->top = -1;
}

void push(MinStack* s, int val) {
    if (s->top == MAX - 1) return;

    s->top++;
    s->data[s->top] = val;

    if (s->top == 0) {
        s->minData[s->top] = val;
    } else {
        int currentMin = s->minData[s->top - 1];
        s->minData[s->top] = (val < currentMin) ? val : currentMin;
    }
}

void pop(MinStack* s) {
    if (s->top == -1) return;
    s->top--;
}

int top(MinStack* s) {
    if (s->top == -1) return -1;
    return s->data[s->top];
}

int getMin(MinStack* s) {
    if (s->top == -1) return -1;
    return s->minData[s->top];
}

int main() {
    MinStack s;
    init(&s);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&s, val);
    }

    printf("%d\n", getMin(&s));
    printf("%d\n", top(&s));

    pop(&s);

    printf("%d\n", getMin(&s));
    printf("%d\n", top(&s));

    return 0;
}