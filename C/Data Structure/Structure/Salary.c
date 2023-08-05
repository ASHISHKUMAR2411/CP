#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// structure within structure 
struct salary
{
    char name[50];
    int employeecode;
    char department[50];
    struct 
    {
        int dearness;
        int gratuity;
        int paidleave;
        int sickleave;
    }allowance;
    int basicpay;
    int bonus;
    int DA;
} employee;
int main()
{
    // here we will give the details of the salary details with many things
   
   char ch[2] ;
    int totalsal=0;
    printf("\n enter the name of the employee : ");
    gets(employee.name);
    printf("\n enter the employee code :");
    scanf("%d",&employee.employeecode);
    printf("\n enter the department of the employee : ");
    gets(ch);
    gets(employee.department);
    printf("\n enter the dearness allowance paid to the employee : ");
    scanf("%d",&employee.allowance.dearness);
    totalsal+=employee.allowance.dearness;
    printf("\n enter the gratuity paid to the employee : ");
    scanf("%d",&employee.allowance.gratuity);
    totalsal+=employee.allowance.gratuity;
    printf("\n enter the paidleave will given to the employee in case of leave taken : ");
    scanf("%d",&employee.allowance.paidleave);
    totalsal+=employee.allowance.paidleave;
    printf("\n enter the sickleave pay to the employee : ");
    scanf("%d",&employee.allowance.sickleave);
    totalsal+=employee.allowance.sickleave;
    printf("\n enter the basic salary of the employee : ");
    scanf("%d",&employee.basicpay);
    totalsal+=employee.basicpay;
    printf("\n enter the bonus given to the employee every month : ");
    scanf("%d",&employee.bonus);
    totalsal+=employee.bonus;
    printf("\n enter the demand aloowance given to the employee : ");
    scanf("%d",&employee.DA);
    totalsal+=employee.DA;
    printf("\n\n\n\n he details of the employee you want to see : \n\n\n");
    printf("\nname of the employee : %s",employee.name);
    printf("\nemployee code : %d",employee.employeecode);
    printf("\ndepartment of the employee : %s",employee.department);
    printf("\ndearness allowance : %d",employee.allowance.dearness);
    printf("\ngratuity paid : %d",employee.allowance.gratuity);
    printf("\npaidleave : %d",employee.allowance.paidleave );
    printf("\nsickleave pay: %d",employee.allowance.sickleave);
    printf("\nbasic salary : %d",employee.basicpay );
    printf("\nbonus : %d",employee.bonus );
    printf("\ndemand Allownace: %d",employee.DA);
    printf("\ntotal salary : %d",totalsal);
    return 0;
}
