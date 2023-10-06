#include "linked_list/single_linked_list.c"

void main()
{
    //system("cls");
    SingleLinkedList sll = createSingleLinkedList();
    appendAll(&sll, 5, 1, 2, 3, 4, 5);
    showAllItems(sll);
    printf("%d",getItemByIndex(sll,6));
}