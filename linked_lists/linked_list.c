#include <stdio.h>
#include <stdlib.h>

/* structs */
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    int size;
    Node *head;
} LinkedList;

/* create structs */
Node *CreateNode(int val) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->val = val;
    return node;
}

LinkedList *CreateLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

/* functions */
void InsertNode(LinkedList *list, Node *node) {
    if (!list->head) {
        list->head = node;
    } else if (list->head->val > node->val) {
        node->next = list->head;
        list->head = node;
    } else {
        Node *head = list->head;
        while (head->next && head->next->val < node->val)
            head = head->next;

        node->next = head->next;
        head->next = node;
    }
    list->size++;
}

void ClearList(LinkedList *list) {
    Node *temp;
    while (list->head) {
        temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
    list->size = 0;
}

void PrintList(LinkedList *list) {
    Node *head = list->head;
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("null\n");
}

/* tests */
int main() {
    LinkedList *list = CreateLinkedList();

    /* test 1 */
    InsertNode(list, CreateNode(1));
    InsertNode(list, CreateNode(2));
    InsertNode(list, CreateNode(3));
    PrintList(list);
    printf("size: %d\n\n", list->size);
    ClearList(list);

    /* test 2 */
    InsertNode(list, CreateNode(1));
    InsertNode(list, CreateNode(2));
    InsertNode(list, CreateNode(3));
    PrintList(list);
    printf("size: %d\n\n", list->size);
    ClearList(list);

    /* test 3 */
    for (int i = 0; i < 10; i++)
        InsertNode(list, CreateNode(rand() % 100));
    PrintList(list);
    printf("size: %d\n\n", list->size);
    ClearList(list);
}
