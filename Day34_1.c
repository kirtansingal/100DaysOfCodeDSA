#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top, int* val) {
    if (top == NULL) return NULL;
    struct Node* temp = top;
    *val = temp->data;
    top = top->next;
    free(temp);
    return top;
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);

    struct Node* top = NULL;

    char* token = strtok(expr, " \n");

    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {

            int b, a;
            top = pop(top, &b);
            top = pop(top, &a);

            int res;
            if (strcmp(token, "+") == 0) res = a + b;
            else if (strcmp(token, "-") == 0) res = a - b;
            else if (strcmp(token, "*") == 0) res = a * b;
            else res = a / b;

            top = push(top, res);
        } else {
            top = push(top, atoi(token));
        }

        token = strtok(NULL, " \n");
    }

    int result;
    top = pop(top, &result);

    printf("%d", result);

    return 0;
}