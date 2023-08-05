// Write a program that uses the function isNumPalindrome that checks if a number is palindrome or not .
#include <bits/stdc++.h>
using namespace std;
bool isNumPalindrome(int n)
{
    int temp = n;
    int rev = 0;
    while(n>0)
    {
        int dig = n%10;
        rev = rev*10 + dig;
        n = n/10;
    }
    if(temp == rev)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if(isNumPalindrome(n))
        cout<<"\nThe number is palindrome";
    else
        cout<<"\nThe number is not palindrome";
    return 0;
}