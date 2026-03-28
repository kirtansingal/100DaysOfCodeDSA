#include <stdio.h>
#include <ctype.h>

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
    char s[10000];
    fgets(s, sizeof(s), stdin);

    int num = 0;
    char sign = '+';

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && c != ' ') || s[i + 1] == '\0') {
            if (sign == '+') push(num);
            else if (sign == '-') push(-num);
            else if (sign == '*') stack[top] = pop() * num;
            else if (sign == '/') stack[top] = pop() / num;

            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    printf("%d", result);

    return 0;
}