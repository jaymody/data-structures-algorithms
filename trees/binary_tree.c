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
    struct Node* root;
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
    struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
    tree->root = NULL;
    return tree;
}

// insert value to binary tree
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

// print tree
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
}
void PrintTree(struct BinaryTree* tree) {
    _PrintTree(tree->root, 0);
    printf("\n");
}


// main
int main() {
    struct BinaryTree* mytree = CreateBinaryTree();
    InsertNode(mytree, 10);
    InsertNode(mytree, 5);
    InsertNode(mytree, 4);
    InsertNode(mytree, 8);
    InsertNode(mytree, 7);
    InsertNode(mytree, 9);
    InsertNode(mytree, 3);
    InsertNode(mytree, 11);
    InsertNode(mytree, 20);
    InsertNode(mytree, 15);
    InsertNode(mytree, 16);
    InsertNode(mytree, 17);
    InsertNode(mytree, 13);

    PrintTree(mytree);
}
