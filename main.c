#include "circular_linked_list/circular_linked_list.h"

int main() {
    CircularLinkedList *cl = createCircularLinkedList();
    insertAtHead(cl,1);
    insertAtHead(cl,2);
    insertAtHead(cl,3);
    insertAtHead(cl,4);
    insertAtHead(cl,5);
    
    return 0;
}
