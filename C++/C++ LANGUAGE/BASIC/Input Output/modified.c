#include<stdio.h>
// not giving proper ans 
int main()
{
    FILE *ptr = fopen("abc.txt","r");
    if(ptr==NULL)
    {
        printf("no such file found. \n");
        return 0;
    }
    char buff[100],ch;
    int words = 0 , lines = 0 , character = 0 ;
    while(fscanf(ptr,"%*s %*s %s ",buff)==1)
    {
        printf("%s\n",buff);
    }
    fclose(ptr);
    FILE *ctr = fopen("abc.txt","r");
    while(fscanf(ctr,"%s",buff)==0)
    {
        words++;
    }
    printf("%d\n",words);
    fclose(ctr);
    FILE *mtr = fopen("abc.txt","r");
    while(fscanf(mtr," %[^\n]",buff)==0)
    {
        lines++;
    }
    printf("%d\n",lines);
    fclose(mtr);
    FILE *ktr = fopen("abc.txt","r");
    while(fscanf(ktr,"%c",ch)==0 && ch !=' ')
    {
        character++;
    }
    printf("%d\n",character);
    fclose(ktr);
    // printf("words are :%d\n lines are :%d\n chracter is :%d ",words,lines,character);
    return 0;
}