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

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct Node* dummy = createNode(0);
    struct Node* curr = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }

    return reverse(dummy->next);
}

struct Node* buildList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* l1 = buildList(n);

    scanf("%d", &m);
    struct Node* l2 = buildList(m);

    struct Node* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}