#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
struct word
{
    char *word;
    int encountered;
    struct word *left;
    struct word *right;
}
struct wordTree
{
    char *para;
    struct word 
};
struct wordTree *create_Token(struct wordTree *ptr)
{
    ptr = (struct wordTree *)malloc(sizeof(struct wordTree));
    ptr->para = (char *)malloc(1000 * sizeof(char));
    printf("\nenter the paragraph about covid-19 : \n ");
    gets(ptr->para);
    ptr->left = NULL;
    ptr->right = NULL;
    char ch[] = " ";
    char *w = strtok(ptr->para, ch);
    ptr->word = (char *)malloc(100 * sizeof(char));
    ptr->word = w;
    w = strtok(NULL, ch);
    while (w != NULL)
    {
        insert(ptr, w);
        w = strtok(NULL, ch);
    }
    return ptr;
}
void insert(struct wordTree *ptr, char *word)
{
    if (ptr == NULL)
    {
        return create_Token(ptr);
    }
    ptr->encountered = 1;
    struct wordTree *ctr = ptr;
    if(ctr->left)
}
int main()
{
    struct wordTree *para[5];
    for (int i = 0; i < 5; i++)
    {
        para[i] = create_Token(para[i]);
    }
}