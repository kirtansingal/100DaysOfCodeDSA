#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isValid(char *s) {
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else {
            if (top == -1) return 0;

            char topChar = pop();

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[MAX];
    scanf("%s", s);

    if (isValid(s)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}