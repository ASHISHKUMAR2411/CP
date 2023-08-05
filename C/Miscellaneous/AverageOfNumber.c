#include<stdio.h>
typedef int I;
typedef char C;
char main()
{
    I  n , A[50] , i , sum=0;
    C ch;
    float avg;
    printf("\n enter Y/y for finding the average ");
    scanf("%c",&ch);
    switch (ch)
    {
    case 'Y': 
        printf("\n  how many numbers you want to give ");
        scanf("%d",&n);
        printf("\n now enter the number by giving spaces between them");
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            sum+=A[i];
        }        /* code */
        break;
    case 'y': printf("\n  how many numbers you want to give ");
        scanf("%d",&n);
        printf("\n now enter the number by giving spaces between them");
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            sum+=A[i];
        }        /* code */
        break;
        
    default: printf("\n you have entered  a wrong word");
        break;
    }
    avg=sum/(float)n;
    printf("the average of %d numbers is:\t %f  ",n,avg);
    return ('a');
}
