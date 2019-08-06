////// Includes //////
#include "../binary_tree.c"

void test1() {
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

////// Main //////
int main() {
    test1();
    return 1;
}
