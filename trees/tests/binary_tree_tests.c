////// Includes //////
#include "../binary_tree.c"

////// Tests //////
void test0() {
    /* null test */
    // Create
    struct BinaryTree* mytree = CreateBinaryTree();
    printf("Is Empty after init:\t%s\n", IsEmpty(mytree) ? "true" : "false");

    // Insert
    printf("Inserting:\t%s\n", "{}");
    printf("Is Empty after Insert:\t%s\n", IsEmpty(mytree) ? "true" : "false");

    // Print
    printf("Print Tree:\n");
    PrintTree(mytree);
    printf("\n");

    // Visits
    printf("PreOrder:\t");
    PreOrderVisit(mytree, PrintNode);

    printf("\nInOrder:\t");
    InOrderVisit(mytree, PrintNode);

    printf("\nPostOrder:\t");
    PostOrderVisit(mytree, PrintNode);

    // Clear
    ClearTree(mytree);
    printf("\nIs Empty after clear:\t%s\n", IsEmpty(mytree) ? "true" : "false");

}
void test1() {
    /* perfect binary tree test */
    // Create
    struct BinaryTree* mytree = CreateBinaryTree();
    printf("Is Empty after init:\t%s\n", IsEmpty(mytree) ? "true" : "false");

    // Insert
    int vals[15] = {10,5,3,8,7,9,2,4,15,13,18,17,19,12,14};
    printf("Inserting:\t%s\n", "{10,5,3,8,7,9,2,4,15,13,18,17,19,12,14}");
    for (int i = 0; i < sizeof(vals)/sizeof(vals[0]); i++)
        InsertNode(mytree, vals[i]);
    printf("Is Empty after insert:\t%s\n", IsEmpty(mytree) ? "true" : "false");

    // Print Tree
    printf("Print Tree:\n");
    PrintTree(mytree);
    printf("\n");

    // Visits
    printf("PreOrder:\t"); 
    PreOrderVisit(mytree, PrintNode);

    printf("\nInOrder:\t"); 
    InOrderVisit(mytree, PrintNode);

    printf("\nPostOrder:\t"); 
    PostOrderVisit(mytree, PrintNode);

    // Clear
    ClearTree(mytree);
    printf("\nIs Empty after clear:\t%s\n", IsEmpty(mytree) ? "true" : "false");
}
void test2() {
    /* perfect binary tree test */
    // Create
    struct BinaryTree* mytree = CreateBinaryTree();
    printf("Is Empty after init:\t%s\n", IsEmpty(mytree) ? "true" : "false");

    // Insert
    int vals[10] = {-10,-1,-3,-8,-4,-29,-2,-14,-15,-13};
    printf("Inserting:\t%s\n", "{-10,-1,-3,-8,-4,-29,-2,-14,-15,-13}");
    for (int i = 0; i < sizeof(vals)/sizeof(vals[0]); i++)
        InsertNode(mytree, vals[i]);
    printf("Is Empty after insert:\t%s\n", IsEmpty(mytree) ? "true" : "false");

    // Print Tree
    printf("Print Tree:\n");
    PrintTree(mytree);
    printf("\n");

    // Visits
    printf("PreOrder:\t"); 
    PreOrderVisit(mytree, PrintNode);

    printf("\nInOrder:\t"); 
    InOrderVisit(mytree, PrintNode);

    printf("\nPostOrder:\t"); 
    PostOrderVisit(mytree, PrintNode);

    // Clear
    ClearTree(mytree);
    printf("\nIs Empty after clear:\t%s\n", IsEmpty(mytree) ? "true" : "false");
}

////// Run Test //////
void run_test(char name[], void (*test)()) {
    printf("############################################################\n");
    printf("##########\t%s\n", name);
    printf("############################################################\n");
    (*test)();
    printf("\n\n\n");
}

////// Main //////
int main() {
    run_test("NULL TEST", test0);
    run_test("PERFECT BINARY TREE TEST", test1);
    run_test("NEGATIVE NUMBERS TEST", test2);
    return 1;
}
