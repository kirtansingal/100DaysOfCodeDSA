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

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) p1 = p1->next;
    } else {
        int diff = len2 - len1;
        while (diff--) p2 = p2->next;
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* temp1 = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head1 == NULL) {
            head1 = newNode;
            temp1 = head1;
        } else {
            temp1->next = newNode;
            temp1 = temp1->next;
        }
    }

    scanf("%d", &m);

    struct Node* head2 = NULL;
    struct Node* temp2 = NULL;

    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head2 == NULL) {
            head2 = newNode;
            temp2 = head2;
        } else {
            temp2->next = newNode;
            temp2 = temp2->next;
        }
    }

    struct Node* inter = getIntersection(head1, head2);

    if (inter != NULL) {
        printf("%d", inter->data);
    } else {
        printf("No Intersection");
    }

    return 0;
}