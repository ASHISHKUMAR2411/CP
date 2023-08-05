// our first session
#include<stdio.h>
int  main(void)
{
    int i,j,k;
    char ch , l[10],ch1[2];
    printf("\n enter the number : ");
    scanf("%d",&i);
    printf("\n enter the string : ");
    gets(ch1);
    gets(l);
    printf("\n enter the character ");// scanf("%s",l) string \0 enter 
    ch=getchar(); //ch='1'
    printf("%s %c %d",l,ch,i);
    puts(l);
    
     
    
}
