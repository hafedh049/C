#include "doubly_linked_list/doubly_linked_list.c"

bool isEven(int a)
{return a % 2;}

void main()
{
    //system("cls");
    DoublyLinkedList *l = createDoublyLinkedList();
    DoublyLinkedList *l1 = createDoublyLinkedList();
    DoublyLinkedList *l2 = createDoublyLinkedList();
    appendAll(l, 12, 1, 8, 7, 4, 5,10,-7,4,0,15,200,333333);
    popFirst(l);
    showAllItems(*l);
    /*splitByPosition(*sll,6,l1,l2);
    showAllItems(*l1);
    showAllItems(*l2);
    sort(l1,-1);
    sort(l2,-1);
    showAllItems(*l1);
    showAllItems(*l2);
    showAllItems(*mergeSorted(*l1,*l2,-1));
    searchWithCriteria(*sll,isEven);*/
}