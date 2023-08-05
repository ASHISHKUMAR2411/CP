#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=10;  // vaild
    int *A=&a;  // vaild
    int **B=&A;  // vaild
    int ***C=&B;   // vaild
    cout<<"a ="<<a<<endl<<"A ="<<*A<<endl<<"B ="<<**B<<endl<<"C ="<<***C;
    return 0; 
}