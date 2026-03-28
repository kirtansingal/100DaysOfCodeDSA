#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            struct Node* start = head;
            while (start != slow) {
                start = start->next;
                slow = slow->next;
            }
            return start;
        }
    }

    return NULL;
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

    struct Node* res = detectCycle(head);

    if (res != NULL) {
        printf("%d", res->data);
    } else {
        printf("null");
    }

    return 0;
}