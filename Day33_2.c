#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    char token[50];

    for (int i = 0; i < n; i++) {
        scanf("%s", token);

        if (strcmp(token, "+") == 0) {
            int b = pop();
            int a = pop();
            push(a + b);
        } else if (strcmp(token, "-") == 0) {
            int b = pop();
            int a = pop();
            push(a - b);
        } else if (strcmp(token, "*") == 0) {
            int b = pop();
            int a = pop();
            push(a * b);
        } else if (strcmp(token, "/") == 0) {
            int b = pop();
            int a = pop();
            push(a / b);
        } else {
            push(atoi(token));
        }
    }

    printf("%d", pop());

    return 0;
}