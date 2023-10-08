#include "linked_list/singly_linked_list.c"

bool isEven(int a)
{return a % 2;}

void main()
{
    //system("cls");
    SingleLinkedList* sll = createSingleLinkedList();
    SingleLinkedList* l1 = createSingleLinkedList();
    SingleLinkedList* l2 = createSingleLinkedList();
    appendAll(sll, 12, 1, 8, 7, 4, 5,10,-7,4,0,15,200,333333);
    showAllItems(*sll);
    splitByPosition(*sll,6,l1,l2);
    showAllItems(*l1);
    showAllItems(*l2);
    sort(l1,-1);
    sort(l2,-1);
    showAllItems(*l1);
    showAllItems(*l2);
    showAllItems(*mergeSorted(*l1,*l2,-1));
    searchWithCriteria(*sll,isEven);
}