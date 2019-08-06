////// Includes //////
#include "../stack.c"

////// Tests //////
void test1() {
    struct Stack* mystack = CreateStack();
    printf("isempty: %s\n", IsEmpty(mystack) ? "true" : "false");
    Push(mystack, 4);
    Push(mystack, 6);
    Push(mystack, 9);
    Push(mystack, 10);
    Push(mystack, 2);
    printf("peek: %d\n", Peek(mystack));
    printf("isempty: %s\n", IsEmpty(mystack) ? "true" : "false");
    PrintStack(mystack);
    Pop(mystack);
    Pop(mystack);
    PrintStack(mystack);
}

////// Main //////
int main() {
    test1();
    return 1;
}
