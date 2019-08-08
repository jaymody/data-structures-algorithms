/* binary search tree implementation */

////// Includes //////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

////// Structs //////
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct BinaryTree {
    struct Node* root;
};


////// Create Structs //////
struct Node* CreateNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct BinaryTree* CreateBinaryTree() {
    struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
    tree->root = NULL;
    return tree;
}


////// Binary Tree Functions ///////
bool IsEmpty(struct BinaryTree* tree) {
    return tree->root == NULL;
}

void _InsertNode(struct Node** node, int val) {
    if (*node == NULL)
        *node = CreateNode(val);
    else if (val <= (*node)->val)
        _InsertNode(&(*node)->left, val);
    else
        _InsertNode(&(*node)->right, val);
}
void InsertNode(struct BinaryTree* tree, int val) {
    _InsertNode(&tree->root, val);
}

void _PreOrderVisit(struct Node* root, void (*fn)(struct Node*)) {
    if (root == NULL)
        return;
    else {
        (*fn)(root);
        _PreOrderVisit(root->left, fn);
        _PreOrderVisit(root->right, fn);
    }
} void PreOrderVisit(struct BinaryTree* tree, void (*fn)(struct Node*)) {
    _PreOrderVisit(tree->root, fn);
} 

void _InOrderVisit(struct Node* root, void (*fn)(struct Node*)) {
    if (root == NULL)
        return;
    else {
        _InOrderVisit(root->left, fn);
        (*fn)(root);
        _InOrderVisit(root->right, fn);
    }
} void InOrderVisit(struct BinaryTree* tree, void (*fn)(struct Node*)) {
    _InOrderVisit(tree->root, fn);
} 

void _PostOrderVisit(struct Node* root, void (*fn)(struct Node*)) {
    if (root == NULL)
        return;
    else {
        _PostOrderVisit(root->left, fn);
        _PostOrderVisit(root->right, fn);
        (*fn)(root);
    }
} void PostOrderVisit(struct BinaryTree* tree, void (*fn)(struct Node*)) {
    _PostOrderVisit(tree->root, fn);
}

void PrintNode(struct Node* node) {
    printf("%d, ", node->val);
}

void FreeNode(struct Node* root) {
    free(root);
} void ClearTree(struct BinaryTree* tree) {
    PostOrderVisit(tree, FreeNode);
    tree->root = NULL;
}

// WARNING: only works for smaller trees with small values
void _PrintTree(struct Node* root, int space) {
    if (root == NULL)
        return;

    space += 10;

    _PrintTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d", root->val);
    
    _PrintTree(root->left, space);
} void PrintTree(struct BinaryTree* tree) {
    _PrintTree(tree->root, 0);
    printf("\n");
}
