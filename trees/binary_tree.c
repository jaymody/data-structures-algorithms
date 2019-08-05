// binary tree implementation
// includes
#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// binary tree structure
struct BinaryTree {
    struct Node* head;
};


// allocate new node
struct Node* CreateNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// allocate new binary tree
struct BinaryTree* CreateBinaryTree() {
    struct BinaryTree* tree = malloc(sizeof(BinaryTree));
    tree->head = NULL;
}

// add value to binary tree
void AddNode(struct Node* node, int val) {
    if (node == NULL)
        node = CreateNode(val);
    else if (val <= node->val)
        AddNode(node->left);
    else if (val > node->val)
        AddNode(node->right);
}
void AddNode(struct BinaryTree* tree, int val) {
    AddNode(tree->head, val);
}

