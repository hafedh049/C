#include "circular_linked_list/circular_linked_list.c"

int main() {
    CircularLinkedList *cl = createCircularLinkedList();
    insertAtTail(cl,1);
    insertAtTail(cl,2);
    insertAtTail(cl,3);
    insertAtTail(cl,4);
    insertAtTail(cl,5);
    printCircularLinkedList(cl);
    return 0;
}
