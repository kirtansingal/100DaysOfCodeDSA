#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* createNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* nodes[1000];

    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n) nodes[i]->left = nodes[left];
            if (right < n) nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);
    if (root == NULL) return 0;

    struct QueueNode queue[2000];
    int front = 0, rear = 0;

    int min_hd = 0, max_hd = 0;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode curr = queue[front++];
        struct TreeNode* node = curr.node;
        int hd = curr.hd;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (node->left) queue[rear++] = (struct QueueNode){node->left, hd - 1};
        if (node->right) queue[rear++] = (struct QueueNode){node->right, hd + 1};
    }

    for (int line = min_hd; line <= max_hd; line++) {
        for (int i = 0; i < rear; i++) {
            if (queue[i].hd == line) {
                printf("%d ", queue[i].node->val);
            }
        }
        printf("\n");
    }

    return 0;
}