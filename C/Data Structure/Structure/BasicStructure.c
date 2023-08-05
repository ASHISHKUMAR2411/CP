#include<stdio.h>
#include<string.h>
#include<string.h>
#include<stdlib.h>
struct ashish
    {
        char familymember[50];
        char relation[30];
        char occupation[50];
        int mobile[15];
        char address[150];
        char status[50];
    } F1[3];
int main()
{
    // using stucture 
    char ch;
    struct ashish *F2;
    ch=getchar();
    for(F2=F1;F2<F1+3;F2++)
    {
        printf("\nenter the  family member name \t ");
        gets(F2->familymember);
        printf("\nenter his/her relation with ashish \t ");
        gets((*F2).relation);
        printf("\nenter the occupation of that member \t ");
        gets(F2->occupation);
        printf("\nenter their mobile number \t");
        gets((char *)(*F2).mobile);
        
        printf("\nenter the status of that member :");
        gets((*F2).status);
        printf("\nenter the address of that member \t");
        gets(F2->address);
    }
    
    printf("\nFamilyMember\t Relation \t occupation    \t Mobile No \t status   \t adrress");
    printf("\n-----------------------------------------------------------------------------------------------------------------------");
    for(F2=F1;F2<F1+3;F2++)
    {
        printf("\n%s",F2->familymember);
        printf("\t %s ",F2->relation);
        printf("\t %s",F2->occupation);
        printf("     \t %s",(*F2).mobile);
        printf("\t %s",(*F2).status);
        printf("\t %s",F2->address);
    }
    
    // F2=F1;
    // F2->mobile++;
    // printf("\n%s\t%s",F2->mobile,F1[0].mobile);
    // F2=&F1[1];
    // (F2->mobile)++;
    // F2++->mobile;
    // printf("\n%s\t%s",F1[1].mobile,F2);
    return 0;

}