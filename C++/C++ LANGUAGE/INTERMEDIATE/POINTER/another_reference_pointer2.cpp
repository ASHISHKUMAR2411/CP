#include<iostream>
using namespace std;
int main()
{
    // segmentation fault 
    int *ptr=NULL;
    int *&ref=ptr;
    cout<<*ptr<<endl<<ptr<<endl<<*&ref<<endl;
    return 0;
}