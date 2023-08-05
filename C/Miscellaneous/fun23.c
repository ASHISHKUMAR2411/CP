#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    //convert all lower ino upper character 
    int n;
    char ch[50];
    printf("\n enter the character string which you want to use \t :");
    gets(ch);
    n=strlen(ch);
    for(int i=0;i<n;i++)
    {
        if(islower(ch[i]))
        {
            ch[i]=toupper(ch[i]);
        }
    } 
    puts(ch);
    return 0;
}
