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

// Insert into BST
struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Find LCA in BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->val && q < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (p > root->val && q > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("%d", lca->val);
    } else {
        printf("-1");
    }

    return 0;
}