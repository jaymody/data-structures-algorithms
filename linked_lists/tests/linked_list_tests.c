////// Includes //////
#include "../linked_list.c"

// main function
void test1() {
    struct LinkedList* mylist = CreateList();
    InsertHead(mylist, 4);
    InsertHead(mylist, 3);
    InsertHead(mylist, 1);
    InsertTail(mylist, 5);

    printf("size: %d \t", Length(mylist));
    PrintList(mylist);

    ReverseList(mylist);
    printf("size: %d \t", Length(mylist));
    PrintList(mylist);

    DeleteHead(mylist);
    printf("size: %d \t", Length(mylist));
    PrintList(mylist);

    DeleteTail(mylist);
    printf("size: %d \t", Length(mylist));
    PrintList(mylist);

    ClearList(mylist);
    printf("size: %d \t", Length(mylist));
    PrintList(mylist);
}

////// Main //////
int main() {
    test1();
    return 1;
}
