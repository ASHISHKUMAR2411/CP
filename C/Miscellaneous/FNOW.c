#include<stdio.h>
#include<string.h>
int main()
{
    char str[50],ch;
    int n , count=0;
    printf("\n enter the string \n");
    gets(str);
    n=strlen(str);
    for(int i=0;i<=n;i++)
    {
        
            switch (str[i])
            {
                case ' ' : if(str[i+1]!=' '&& str[i+1]!='\0')
                           {
                              /*if(str[i-1]==' ');
                              */
                    
                              
                              //else
                              //{
                                count++;
                              //}    
                            }
                            break;           

        
                default:
                            break;
            }
            
        /*        
        if(str[i]==' ')
        {
            for(int j=i;j<=n;j++)
            {
                if(str)
            }
        }*/
    }
    printf("\n the no of words in the string is : %d",count+1);
    return 0;
}