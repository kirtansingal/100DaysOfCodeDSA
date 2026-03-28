#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) return root;

    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    // Input elements to build BST
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    int key;
    scanf("%d", &key);

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL) {
        printf("Found\n");
        // Optional: print subtree rooted at found node
        inorder(result);
    } else {
        printf("Not Found\n");
    }

    return 0;
}