// binary search tree implementation
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





// pre order visit
void _PreOrderVisit(struct Node* root, void (*fn)(struct Node*)) {
    if (root == NULL)
        return;
    else {
        (*fn)(root);
        _PreOrderVisit(root->left, fn);
        _PreOrderVisit(root->right, fn);
    }
}
void PreOrderVisit(struct BinaryTree* tree, void (*fn)(struct Node*)) {
    _PreOrderVisit(tree->root, fn);
} 

// in order visit
void _InOrderVisit(struct Node* root, void (*fn)(struct Node*)) {
    if (root == NULL)
        return;
    else {
        _InOrderVisit(root->left, fn);
        (*fn)(root);
        _InOrderVisit(root->right, fn);
    }
}
void InOrderVisit(struct BinaryTree* tree, void (*fn)(struct Node*)) {
    _InOrderVisit(tree->root, fn);
} 

// postvisit
void _PostOrderVisit(struct Node* root, void (*fn)(struct Node*)) {
    if (root == NULL)
        return;
    else {
        _PostOrderVisit(root->left, fn);
        _PostOrderVisit(root->right, fn);
        (*fn)(root);
    }
}
void PostOrderVisit(struct BinaryTree* tree, void (*fn)(struct Node*)) {
    _PostOrderVisit(tree->root, fn);
}

// print value at node
void PrintNode(struct Node* node) {
    printf("%d, ", node->val);
}




// clear tree
void ClearTree(struct BinaryTree* tree) {

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
    InsertNode(mytree, 3);
    InsertNode(mytree, 8);
    InsertNode(mytree, 7);
    InsertNode(mytree, 9);
    InsertNode(mytree, 2);
    InsertNode(mytree, 4);
    InsertNode(mytree, 15);
    InsertNode(mytree, 13);
    InsertNode(mytree, 18);
    InsertNode(mytree, 17);
    InsertNode(mytree, 19);
    InsertNode(mytree, 12);
    InsertNode(mytree, 14);

    PrintTree(mytree);

    printf("PreOrder:\t");
    PreOrderVisit(mytree, PrintNode);
    printf("\nInOrder:\t");
    InOrderVisit(mytree, PrintNode);
    printf("\nPostOrder:\t");
    PostOrderVisit(mytree, PrintNode);
    printf("\n");
}
