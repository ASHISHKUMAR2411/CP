#include<bits/stdc++.h>
using namespace std;
int gcd2(int a, int b) { 
    if(b==0)
        return a;
    else{
        return gcd2(b, a % b);
    }
}
int gcd1(int a , int b){
    while(a!=b){
        if(a>b)
            a = a-b;
        else
            b = b - a;
    }
    return a;
}
int main(){
    int a, b;
    cin>>a>>b;
    // 1st method of finding gcd basic euclidean
    cout<<gcd1(a,b)<<endl;

    // using inbuilt
    cout << __gcd(a, b) << endl;

    // using optimized eculid with recursion
    cout << gcd2(a, b)<<endl;
}