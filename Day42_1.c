#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    int queue[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    while (front <= rear) {
        push(queue[front++]);
    }

    while (top != -1) {
        printf("%d ", pop());
    }

    return 0;
}