/* singly linked list implementation */
// includes
#include <stdio.h>
#include <stdlib.h>


// node structure
struct Node {
    int val;
    struct Node* next;
};

// singly linked list structure
struct LinkedList {
    int size;
    struct Node* head;
};


// allocate new Node
struct Node* CreateNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->val = val;
    return node;
}

// allocate new LinkedList
struct LinkedList* CreateList() {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}


// insert node at head
void InsertHead(struct LinkedList* list, int val) {
    struct Node* node = CreateNode(val);
    node->next = list->head;
    list->head = node;
    list->size++;
}

// delete head node
void DeleteHead(struct LinkedList* list) {
    if (list->head) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
}

// insert node at tail
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

// delete tail node
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

// reverse the list
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

// print values in list
void PrintList(struct LinkedList* list) {
    struct Node* node = list->head;

    while (node != NULL) {
        printf("%d, ", node->val);
        node = node->next;
    }
    printf("\n");
}

// get length (number of nodes) in list
int Length(struct LinkedList* list) {
    return list->size;
}
 

// main function
int main() {
    struct LinkedList* mylist = CreateList();
    InsertHead(mylist, 4);
    InsertHead(mylist, 3);
    InsertHead(mylist, 1);
    InsertTail(mylist, 5);

    PrintList(mylist);
    ReverseList(mylist);
    PrintList(mylist);
    DeleteHead(mylist);
    PrintList(mylist);
    DeleteTail(mylist);
    PrintList(mylist);

    return 0;
}
