#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void changeit(int m);
int main()
{
    // here we convert the month number to month name
    int m;
    printf("\n enter the month number you want to see what name it is called\t :");
    scanf("%d",&m);
    changeit(m);
    return 0;
}
void changeit(int m)
{
    switch (m)
    {
        case 1 : printf("\n it is called January");
            
            break;
        case 2 : printf("\n it is called Febuary");
            
            break;
        case 3 : printf("\n it is called March");
            
            break;
        case 4  : printf("\n it is called April");
            
            break;
        case 5 : printf("\n it is called May ");
            
            break;
        case 6 : printf("\n it is called June");
            
            break;
        case 7: printf("\n it is called July ");
            
            break;
        case 8 : printf("\n it is called August ");
            
            break;
        case 9 : printf("\n it is called September ");
            
            break;
        case 10 : printf("\n it is called October");
            
            break;
        case 11 : printf("\n it is called November ");
            
            break;
        case 12 : printf("\n it is called December ");
            
            break;
        
        
        default: printf("\nthis number is not valid month number are between 1-12 \n thank for your time appreciate it ");
            break;
    }
    
}