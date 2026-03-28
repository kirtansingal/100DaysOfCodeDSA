#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void preorder(struct Node* root, int result[], int* idx) {
    if (root == NULL) return;
    result[(*idx)++] = root->data;
    preorder(root->left, result, idx);
    preorder(root->right, result, idx);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* nodes[1000];

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (val == -1) {
            nodes[i] = NULL;
        } else {
            nodes[i] = (struct Node*)malloc(sizeof(struct Node));
            nodes[i]->data = val;
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n) nodes[i]->left = nodes[left];
            if (right < n) nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    int result[1000];
    int idx = 0;

    preorder(root, result, &idx);

    for (int i = 0; i < idx; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}