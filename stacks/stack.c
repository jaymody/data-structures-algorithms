/* stack implementation */

////// Includes //////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


////// Structs //////
struct Node {
    int val;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};


////// Create Structs //////
struct Node* CreateNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

struct Stack* CreateStack() {
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}


////// Stack Functions //////
bool IsEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void Push(struct Stack* stack, int val) {
    struct Node* node = CreateNode(val);
    node->next = stack->top;
    stack->top = node;
}

void Pop(struct Stack* stack) {
    if (!IsEmpty(stack)) {
        struct Node* temp = stack->top->next;
        free(stack->top);
        stack->top = temp;
    }
}

int Peek(struct Stack* stack) {
    return stack->top->val;
}

void PrintStack(struct Stack* stack) {
    struct Node* node = stack->top;
    while (node) {
        printf("%d, ", node->val);
        node = node->next;
    }
    printf("\n");
}


////// Main ///////
int main() {
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
