#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int prior;
    int data;
    struct queue *next;
};
