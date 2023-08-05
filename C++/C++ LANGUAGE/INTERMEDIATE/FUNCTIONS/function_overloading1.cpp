#include<bits/stdc++.h>
using namespace std;
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
