#include "binary_tree/tree.c"

void main()
{
    //system("cls");
    TreeNode* root = createNode(10);
    insert(&root,20);
    insert(&root,210);
    insert(&root,40);
    insert(&root,0);
    insert(&root,-1);
    printTree(root,0);
}