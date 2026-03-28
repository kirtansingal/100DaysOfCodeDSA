#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    queue[++rear] = val;
}

void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    display();

    return 0;
}