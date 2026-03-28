#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* removeElements(struct Node* head, int val) {
    while (head != NULL && head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == val) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    int val;
    scanf("%d", &val);

    head = removeElements(head, val);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}