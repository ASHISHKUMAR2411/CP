#include<iostream>
using namespace std;
template<class T>
void create(T *ptr, int size)
{
    if(ptr)
    {
        for(int i=0;i<size;i++)
        {
            cout<<"enter the element :";
            cin>>*(ptr+i);
        }
    }
}
template<class T>
void print(T *ptr,int size)
{
    if(ptr)
    {
        for(int i =0;i<size;i++)
        {
            cout<<" "<<*(ptr+i);
        }
    }
}
int main()
{
    string *temp = new(nothrow) string[100];
    int size;
    cin>>size;
    if(temp)
    {
        create<string>(temp,size);
        print<string>(temp,size);
    }
    delete[] temp;
    return 0;
}