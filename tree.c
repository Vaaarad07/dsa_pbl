#include "stdio.h"
#include "stdlib.h"


typedef struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
} BSTnode;
BSTnode *insert(BSTnode *, int);
BSTnode *createTree()
{
    int n, x, i;
    BSTnode *root = NULL;
    printf("Enter number of nodes:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the next tree value:\n");
        scanf("%d", &x);
        root = insert(root, x);
    }
    return (root);
}
int search(BSTnode *root, int key)
{
    BSTnode *temp = root;
    while (temp != NULL)
    {
        if (key == temp->data)
            return 1;
        else if (key > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return 0;
}
void inorder(BSTnode *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d\t", T->data);
        inorder(T->right);
    }
}
void preorder(BSTnode *T)
{
    if (T != NULL)
    {
        printf("%d\t", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
void postorder(BSTnode *T)
{
    if (T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d\t", T->data);
    }
}


BSTnode *insert(BSTnode *T, int data)
{
    BSTnode *newNode, *traverse, *allocate;
    newNode = (BSTnode *)malloc(sizeof(BSTnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (T == NULL)
        return (newNode);
    traverse = T;
    while (traverse != NULL)
    {
        allocate = traverse;
        if (data > traverse->data)
            traverse = traverse->right;
        else if (data < traverse->data)
            traverse = traverse->left;
        else
        {
            printf("Duplicate entry; sanitize inputs!\n");
            return (T);
        }
    }
    if (data > allocate->data)
        allocate->right = newNode;
    else
        allocate->left = newNode;
    return (T);
}