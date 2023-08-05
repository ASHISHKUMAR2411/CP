// C program to execute avl tree using insertion and rotation

#include<stdio.h>
#include<stdlib.h>
// structure of  node 
struct avl
{
    int data;
    struct avl *left;
    struct avl *right;
    int height;
}

// Create Node 