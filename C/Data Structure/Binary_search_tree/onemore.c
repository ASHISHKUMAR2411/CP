/*Adarsh Kumar
2020KUCP1016
Batch 'A1'
Date:9th July 2021*/

#include <stdio.h>
#include <stdlib.h>

struct binary
{
    int key;
    struct binary *left, *right;
};

struct binary *newNode(int item)
{
    struct binary *temp = (struct binary *)malloc(sizeof(struct binary));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct binary *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct binary *inserting(struct binary *binary, int key)
{

    if (binary == NULL)
        return newNode(key);

    if (key < binary->key)
        binary->left = inserting(binary->left, key);
    else if (key > binary->key)
        binary->right = inserting(binary->right, key);

    return binary;
}

int main()
{

    int a[50];
    int n;
    printf("Enter the number of values you want to insert\n");
    scanf("%d", &n);
    printf("Enter the values of the tree you want to inserting : \n");
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