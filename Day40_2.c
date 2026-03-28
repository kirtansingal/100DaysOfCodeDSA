#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if (top >= 0) top--;
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int temp[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp[i]);
    }

    int result[MAX];

    for (int i = 0; i < n; i++) {
        result[i] = 0;
    }

    int s[MAX];
    int t = -1;

    for (int i = 0; i < n; i++) {
        while (t != -1 && temp[i] > temp[s[t]]) {
            int idx = s[t--];
            result[idx] = i - idx;
        }
        s[++t] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}