#include<bits/stdc++.h>
using namespace std;
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int count = 6 , A[5]={0,0,0,0} ,space =0;
    for(int i =0;i<n;i++)
    {
        if(password[i]==32)
        {
            break;
        }
        space++;
    }
    n = space;
    if(n==0)
    {
        return count;
    }
    if(n>0)
    {
        count--;
    }
    if(n<6)
    {
        for(int i =0;i<n;i++)
        {
            if(password[i]>=48 && password[i]<=57)
            {
                A[0]++;
            }
            if(password[i]>=65 && password[i]<=90)
            {
                A[1]++;
            }
            if(password[i]>=97 && password[i]<=122)
            {
                A[2]++;
            }
            if(password[i]==33 || password[i] == 94 || password[i] == 64|| password[i]== 45 || (password[i]>=35 && password[i]<=38) || (password[i]>=40 && password[i]<=43))
            {
                A[3]++;
            }
        }
    }
    else if(n>=6)
    {
        count--;
        for(int i =0;i<n;i++)
        {
            if(password[i]>=48 && password[i]<=57)
            {
                A[0]++;
            }
            if(password[i]>=65 && password[i]<=90)
            {
                A[1]++;
            }
            if(password[i]>=97 && password[i]<=122)
            {
                A[2]++;
            }
            if(password[i]==33 || password[i] == 94 || password[i] == 64|| password[i]== 45 || (password[i]>=35 && password[i]<=38) || (password[i]>=40 && password[i]<=43))
            {
                A[3]++;
            }
        }
    }
    for(int i =0;i<4;i++)
    {
        if(A[i]!=0)
        {
            count--;
        }
    }
    if(n<6)
    {
        if((count+n)>6)
        {
            count--;
        }
        else
        {
            count++;
        }
        return count;
    }
    else
    {
        return count;
    }
}
int main()
{
    string s;
    cout<<"\nenter the string : ";
    getline(cin,s);
    int need = minimumNumber(s.length(),s);
    cout<<"\nrequire this much : "<<need;
    return 0;
}