#include<stdio.h>
// using namespace std;
// error in this code as c does not support the function overloading
void foo(char c)
{
printf("From foo: char");
}
void foo(int i)
{
printf("From foo: int");
}

int main()
{
foo('V');
foo(1);
return 0;
}
