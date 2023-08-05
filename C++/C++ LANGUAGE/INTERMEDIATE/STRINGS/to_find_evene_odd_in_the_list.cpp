// CPP program to find the even and odd number in the list 
// using find_first_of
#include<bits/stdc++.h>
using namespace std;
  
// Defining the Predicate Function to find first occurrence
// of an odd number
bool pred( int a, int b)
{
    if (a % b != 0) {
        return 1;
    } else {
        return 0;
    }
}
  
// Defining the Predicate Function to find first occurrence
// of an even number
bool pred1( int a, int b)
{
    if (a % b == 0) {
        return 1;
    } else {
        return 0;
    }
}
int main()
{
    vector<int> v1,v2 = {2};
    char ch;
    int temp,n;
    cout<<"\nenetre the element in which you want to find the odd and even ";
    cout<<"\n Now enter number of  element you want  : ";
    cin>>n;
    for(int i= 0;i<n;i++)
    {
        cout<<"enter the element : ";
        cin>>temp;
        v1.push_back(temp);
    }
    auto ip = v1.begin();
    while(ip!=v1.end())
    {
        ip = find_first_of(ip,v1.end(),v2.begin(),v2.end(),pred);
        cout<<"\n the odd element is : "<<*(ip)<<" found st position "<<(ip-v1.begin());
        ip = ip+1;
    }
    ip = v1.begin();
    while(ip!=v1.end())
    {
        ip = find_first_of(ip,v1.end(),v2.begin(),v2.end(),pred1);
        cout<<"\n the even element is : "<<*ip<<" found st position "<<(ip-v1.begin());
        ip = ip+1;
    }
    return 0;
}