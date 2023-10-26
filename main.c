#include "circular_linked_list/circular_linked_list.c"

int main() {
    CircularLinkedList *cl = createCircularLinkedList();
    insertAtHead(cl,1);
    insertAtHead(cl,2);
    insertAtHead(cl,3);
    insertAtHead(cl,4);
    insertAtHead(cl,5);
    printCircularLinkedList(cl);
    return 0;
}
