#include "circular_linked_list/circular_linked_list.c"

int main() {
    CircularLinkedList *cl = createCircularLinkedList();
    CircularLinkedList *c2 = createCircularLinkedList();
    insertAtHead(cl,3);
    insertAtHead(cl,1);
    insertAtHead(cl,3);
    /*insertAtHead(cl,4);
    insertAtHead(cl,5);*/
    showAllItems(*cl);
    deleteNodeAtPosition(cl,1);
    showAllItems(*cl);
    return 0;
}
