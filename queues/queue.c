/* queue implementation */

////// Includes //////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


////// Structs //////
typedef struct NodeT {
    int val;
    struct NodeT* next;
    struct NodeT* prev;
} Node;

typedef struct {
    Node* front;
    Node* back;
} Queue;


////// Create Structs //////
Node* CreateNode(int val) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Queue* CreateQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}


////// Queue Functions //////
bool IsEmpty(Queue* queue) {
    return queue->front == NULL;
}

void Push(Queue* queue, int val) {
    if (!queue->front) {
        queue->front = CreateNode(val);
        queue->back = queue->front;
    }
    else {
        Node* node = CreateNode(val);
        node->next = queue->back;
        queue->back->prev = node;
        queue->back = node;
    }
}

int Pop(Queue* queue) {
    if (IsEmpty(queue)) return -1;

    Node* node = queue->front->prev;
    int val = queue->front->val;
    free(queue->front);
    queue->front = node;
    return val;
}

int Front(Queue* queue) {
    return IsEmpty(queue) ? -1 : queue->front->val;
}

int Back(Queue* queue) {
    return IsEmpty(queue) ? -1 : queue->back->val;
}

void BackToFront(Queue* queue, void (*fn)(Node*)) {
    Node* node = queue->back;
    while (node) {
        fn(node);
        node = node->next;
    }
}

void FrontToBack(Queue* queue, void (*fn)(Node*)) {
    Node* node = queue->front;
    while (node) {
        fn(node);
        node = node->prev;
    }
}

void PrintNode(Node* node) {
    printf("%d, ", node->val);
}