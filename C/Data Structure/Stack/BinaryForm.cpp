// CPP program to covert the number into binary form in typical computer style 
#include<bits/stdc++.h>
using namespace std;
void binaryForm(int number);
int main()
{
    int number;
    cout<<"enter the NUMBER you want to find its Binary form : ";
    cin>>number;
    cout<<INT16_MAX<<" "<<INT16_MIN<<" "<<INT32_MAX<<" "<<INT32_MIN<<" "<<INT64_MAX<<" "<<INT64_MIN<<" "<<INT8_MAX<<" "<<INT8_MIN;
    binaryForm(number);
    return 0;
}
void binaryForm(int number)
{
    int size = CHAR_BIT*sizeof(number);
    stack<bool> Stack;
    for (int  i = 1; i <= size; i++)
    {
        /* code */
        Stack.push(number%2);
        number = number/2;
    }
    for(int i =1 ;i<=size;i++)
    {
        cout<<Stack.top();
        Stack.pop();
        if(i%CHAR_BIT==0)
        {
            cout<<" ";
        }
    }
}
