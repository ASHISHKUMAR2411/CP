// c++ program to implement the linear search and in this it takes O(n) time 


#include<bits/stdc++.h>
using namespace std;
// Linear search will return the position of the number in that array ;
int linearSearch(vector<int> s , int n)
{
    for(int i =0;i<(int)(s.size());i++)
    {
        if(s[i]==n)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> s(10);
    for(auto i = s.begin();i!=s.end();i++)
    {
        cin>>*i;
    }
    cout<<"enter the number to search : ";
    int n;
    cin>>n;
    if(linearSearch(s,n) == -1) {cout<<"element not found";} else {cout<<linearSearch(s,n);}
}