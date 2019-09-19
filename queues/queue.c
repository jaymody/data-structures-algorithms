/* queue implementation */

////// Includes //////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


////// Structs //////
struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Queue {
    struct Node* front;
    struct Node* back;
};


////// Create Structs //////
struct Node* CreateNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct Queue* CreateQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}


////// Queue Functions //////
bool IsEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void Push(struct Queue* queue, int val) {
    if (!queue->front) {
        queue->front = CreateNode(val);
        queue->back = queue->front;
    }
    else {
        struct Node* node = CreateNode(val);
        node->next = queue->back;
        queue->back->prev = node;
        queue->back = node;
    }
}

int Pop(struct Queue* queue) {
    if (!IsEmpty(queue)) {
        struct Node* node = queue->front->prev;
        int val = queue->front->val;
        free(queue->front);
        queue->front = queue->front->prev;
        free(node);
        node = NULL;
        return val;
    }
}

int Front(struct Queue* queue) {
    if (!IsEmpty(queue))
        return queue->front->val;
}

int Back(struct Queue* queue) {
    if (!IsEmpty(queue))
        return queue->back->val;
}

void Forwards(struct Queue* queue, void (*fn)(struct Node*)) {
    struct Node* node = queue->back;
    while (node) {
        fn(node);
        node = node->next;
    }
}

void Backwards(struct Queue* queue, void (*fn)(struct Node*)) {
    struct Node* node = queue->front;
    while (node) {
        fn(node);
        node = node->prev;
    }
}

void PrintNode(struct Node* node) {
    printf("%d, ", node->val);
}