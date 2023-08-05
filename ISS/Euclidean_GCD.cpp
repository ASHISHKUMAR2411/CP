#include<bits/stdc++.h>
using namespace std;

// gcd O(min(A,B)) with recursion not a good approach or competitive use __gcd(a,b) instead
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(){
    int a,b;
    cout << "Enter two numbers with space between them for finding there GCD : ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is : " << gcd(a, b) << endl;
}