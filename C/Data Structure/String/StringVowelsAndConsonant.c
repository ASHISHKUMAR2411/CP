#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n, count=0;
    char ch[24];
    printf("\n enter the string in which you want to find the consonant and vowel \t");
    gets(ch);
    n=strlen(ch);
    for( int i=0;i<n;i++)
    {
    switch(ch[i])
    {
        case 'a':
        case  'A' : count++;
                    break;
        case 'e':
        case  'E' : count++;
                    break;
        case 'i':
        case  'I' : count++;
                    break;
        case 'o':
        case  'O' : count++;
                    break; 
        case 'u':
        case  'U' : count++;
                    break; 
        default: break;

    }
    }
    printf("\n the number of vowel is \t %d \n the consonant are \t %d \n ",count,n-count );
    return 0;


}