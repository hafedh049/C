#include "circular_linked_list/circular_linked_list.c"

int main() {
    CircularLinkedList *cl = createCircularLinkedList();
    CircularLinkedList *c2 = createCircularLinkedList();
    insertAtHead(cl,3);
    insertAtHead(cl,1);
   
    showAllItems(*cl);
    insertNodeAfterNode(cl,cl->head->next->next,100);
    showAllItems(*cl);
    
    return 0;
}
