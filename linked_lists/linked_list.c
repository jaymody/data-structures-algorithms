/* singly linked list implementation */

////// Includes //////
#include <stdio.h>
#include <stdlib.h>


////// Structs ///////
struct Node {
    int val;
    struct Node* next;
};

struct LinkedList {
    int size;
    struct Node* head;
};


////// Create Structs ///////
struct Node* CreateNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->val = val;
    return node;
}

struct LinkedList* CreateList() {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}


////// Linked List Functions //////
void InsertHead(struct LinkedList* list, int val) {
    struct Node* node = CreateNode(val);
    node->next = list->head;
    list->head = node;
    list->size++;
}

void DeleteHead(struct LinkedList* list) {
    if (list->head) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
}

void InsertTail(struct LinkedList* list, int val) {
    struct Node* new_node = CreateNode(val);

    if (!list->head)
        list->head = new_node;
    else {
        struct Node* node = list->head;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new_node;
    }

    list->size++;
}

void DeleteTail(struct LinkedList* list) {
    if (list->head) {
        struct Node* node = list->head;
        struct Node* prev = NULL;

        do {
            prev = node;
            node = node->next;
        } while(node->next != NULL);

        free(node);
        prev->next = NULL;
        list->size--;
    }
}

void ReverseList(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* rev = NULL;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        temp->next = rev;
        rev = temp;
    }

    list->head = rev;
}

void PrintList(struct LinkedList* list) {
    struct Node* node = list->head;

    while (node != NULL) {
        printf("%d, ", node->val);
        node = node->next;
    }
    printf("\n");
}

void ClearList(struct LinkedList* list) {
    struct Node* node = list->head;

    while (node != NULL) {
        list->head = node->next;
        free(node);
        node = list->head;
    }

    free(list->head);
    list->size = 0;
}

int Length(struct LinkedList* list) {
    return list->size;
}
