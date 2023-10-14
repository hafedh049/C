#include "tree.h"

void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("\e[1;32m%d \e[1;33m-> \e[0m", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("\e[1;32m%d \e[1;33m-> \e[0m", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("\e[1;32m%d \e[1;33m-> \e[0m", root->data);
}

TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(TreeNode **root, int value)
{

    if (!(*root))
    {
        TreeNode *tmp = NULL;
        tmp = (TreeNode *)malloc(sizeof(TreeNode));
        tmp->left = tmp->right = NULL;
        tmp->data = value;
        *root = tmp;
        return;
    }
    if (value < (*root)->data)
        insert(&((*root)->left), value);
    else if (value > (*root)->data)
        insert(&((*root)->right), value);
}

TreeNode *search(TreeNode *root, int value)
{
    if (!(root))
        return NULL;
    if (value == root->data)
        return root;
    else if (value < root->data)
        search(root->left, value);
    else if (value > root->data)
        search(root->right, value);
}

void delete_tree(TreeNode **root)
{
    if (*root)
    {
        delete_tree(&(*root)->left);
        delete_tree(&(*root)->right);
        free((*root));
    }
}

TreeNode *findMinValueNode(TreeNode *node)
{
    if (node == NULL)
        return NULL;

    while (node->left != NULL)
        node = node->left;

    return node;
}

void deleteNode(TreeNode **root, int key)
{
    if (*root == NULL)
        return;

    if (key < (*root)->data)
        deleteNode(&((*root)->left), key);
    else if (key > (*root)->data)
        deleteNode(&((*root)->right), key);
    else
    {
        if ((*root)->left == NULL)
        {
            TreeNode *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL)
        {
            TreeNode *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else
        {
            TreeNode *temp = findMinValueNode((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
        }
    }
}

void printTree(TreeNode* root, int space) {
    if (root == NULL) return;

    // Increase distance between levels
    space += 5;

    // Process the right child first
    printTree(root->right, space);

    // Print current node with edges
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("\e[1;32m%d\e[0m", root->data);

    // Process the left child
    printTree(root->left, space);
}