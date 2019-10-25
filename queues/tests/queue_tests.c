////// Includes //////
#include "../queue.c"

////// Tests //////
void test0() {
    /* null test */
    // Create
    Queue* myqueue = CreateQueue();
    printf("Is Empty after init:\t%s\n", IsEmpty(myqueue) ? "true" : "false");

    // Pushing
    printf("Pushing:\t%s\n", "{}");
    printf("Is Empty after Insert:\t%s\n\n", IsEmpty(myqueue) ? "true" : "false");

    // Print
    printf("Front:\t%d\n", Front(myqueue));
    printf("Back:\t%d\n", Back(myqueue));
    printf("FrontToBack:\t");
    FrontToBack(myqueue, PrintNode);
    printf("\n");

    printf("BackToFront:\t");
    BackToFront(myqueue, PrintNode);
    printf("\n\n");

    // Pop
    printf("Popping:\n");
    printf("returned: %d\tFrontToBack: ", Pop(myqueue));
    FrontToBack(myqueue, PrintNode);
    printf("\n\n");

    // Verify Empty
    printf("Is Empty after Pop:\t%s\n", IsEmpty(myqueue) ? "true" : "false");
    printf("Front:\t%d\n", Front(myqueue));
    printf("Back:\t%d\n", Back(myqueue));

    // // Clear
    // ClearTree(myqueue);
    // printf("\nIs Empty after clear:\t%s\n", IsEmpty(myqueue) ? "true" : "false");
}
void test1() {
    /* ordered test */
    // Create
    Queue* myqueue = CreateQueue();
    printf("Is Empty after init:\t%s\n", IsEmpty(myqueue) ? "true" : "false");

    // Pushing
    int vals[5] = {1,2,3,4,5};
    printf("Pushing:\t%s\n", "{1,2,3,4,5}");
    for (int i = 0; i < sizeof(vals)/sizeof(vals[0]); i++)
        Push(myqueue, vals[i]);
    printf("Is Empty after Insert:\t%s\n\n", IsEmpty(myqueue) ? "true" : "false");

    // Print
    printf("Front:\t%d\n", Front(myqueue));
    printf("Back:\t%d\n", Back(myqueue));
    printf("FrontToBack:\t");
    FrontToBack(myqueue, PrintNode);
    printf("\n");

    printf("BackToFront:\t");
    BackToFront(myqueue, PrintNode);
    printf("\n\n");

    // Pop
    printf("Popping:\n");
    for (int i = 0; i < 5; i++) {
        printf("returned: %d\tFrontToBack: ", Pop(myqueue));
        FrontToBack(myqueue, PrintNode);
        printf("\n");
    }
    printf("\n\n");

    // Verify Empty
    printf("Is Empty after Pop:\t%s\n", IsEmpty(myqueue) ? "true" : "false");
    printf("Front:\t%d\n", Front(myqueue));
    printf("Back:\t%d\n", Back(myqueue));
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
    run_test("ORDERED TEST", test1);
    return 1;
}
