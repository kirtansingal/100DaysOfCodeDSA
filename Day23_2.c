#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    int pos;
    scanf("%d", &pos);

    if (pos != -1) {
        struct Node* cycleNode = head;
        for (int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }
        temp->next = cycleNode;
    }

    if (hasCycle(head)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}