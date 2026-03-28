#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    char expr[MAX];
    scanf("%s", expr);

    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isalnum(c)) {
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}