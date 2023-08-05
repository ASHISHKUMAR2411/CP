#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct personal
{
    unsigned age       :7;
    unsigned sex       :1;
    unsigned m_status  :1;
    unsigned children  :3;

} emp ;
int main()
{
    // bit fields example they cannot use scanf
    int age,children,sex,m_status;
    
    printf("\n enter the employee age : \t ");
    scanf("%u",&age);
    emp.age=age;
    printf("\n enter the employee sex, 1 for male and 0 for female : \t ");
    scanf("%u",&sex);
    emp.sex=sex;
    printf("\n enter the martial status of the employee 0 for not married and 1 for married :\t ");
    scanf("%u",&m_status);
    emp.m_status=m_status;
    if(emp.m_status!=0)
    {
        printf("\n enter the number of children of the employee : \t ");
        scanf("\n%u",&children);
        emp.children=children;
    }
    printf("\n\n\n");
    printf("\nemployee age : \t %u",emp.age);
    if(emp.sex==1)
    {
        printf("\n the employee is male");
    }
    else
    {
        printf("\n the employee is female ");
    }
    if(emp.m_status==1)
    {
        printf("\n employee is married ");
        printf("\n the number of children in the family is:  %u ",emp.children);
    }
    else
    {
        printf("\n employee is not married ");
    }
    return 0;
    
}
