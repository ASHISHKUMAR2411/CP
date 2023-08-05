// C program to demonstrate inserting
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>

struct binary
{
    int key;
    struct binary *left, *right;
};

// A utility function to create a new BST binary
struct binary *newNode(int item)
{
    struct binary *temp = (struct binary *)malloc(sizeof(struct binary));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct binary *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

/* A utility function to inserting
a new node with given key in
* BST */
struct binary *inserting(struct binary *binary, int key)
{
    /* If the tree is empty, return a new binary */
    if (binary == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < binary->key)
        binary->left = inserting(binary->left, key);
    else if (key > binary->key)
        binary->right = inserting(binary->right, key);

    /* return the (unchanged) node pointer */
    return binary;
}
void display(struct binaryTree *ptr, int level)
{
    if (ptr == NULL)
    {
        print_tabs(level);
        printf("----<empty>----\n");
        return;
    }
    print_tabs(level);
    printf(" Value = %d\n", ptr->key);
    print_tabs(level);
    printf("left\n");
    display(ptr->left, level + 1);
    print_tabs(level);
    printf("right\n");
    display(ptr->right, level + 1);
    print_tabs(level);
    printf("done\n");
}
void display_all(struct binaryTree *ptr)
{
    display(ptr, 0);
}
void print_tabs(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("\t");
    }
}
int main()
{

    int a[50];
    int n ;
    printf("\nenter the value of n : ");
    scanf("%d",&n);
    printf("enter the values of the tree you want to inserting : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    struct binary *root = NULL;
    root = inserting(root, a[0]);
    int i = 1;
    while (i < n)
    {
        inserting(root, a[i]);
        i = i + 1;
    }
    printf("\nthe tree is : \n");
    inorder(root);

    return 0;
}