#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) return true;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverse(slow->next);
    struct Node* firstHalf = head;

    struct Node* temp1 = firstHalf;
    struct Node* temp2 = secondHalf;

    bool result = true;

    while (temp2 != NULL) {
        if (temp1->data != temp2->data) {
            result = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (isPalindrome(head)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}