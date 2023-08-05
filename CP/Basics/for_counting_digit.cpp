#include<bits/stdc++.h>
using namespace std;
int count(int p){
    if(p){
        return 1 + count(p / 10);
    }
    else{
        return 0;
    }
}
int main(){
    cout<<"enter the number : ";
    int n , res , p ;
    cin>>n;
    p = n;
    res = 0;
    // 1st Method
    while(p){
        res++;
        p/=10;
    }
    cout<<"Number of digit is : "<<res << endl;
    res = 0;
    p = n;
    // 2nd Method using recursion
    res = count(p);
    cout << "Result is " <<res<< endl;
    res = 0;
    p = n;
    // 3rd Method use inbuilt function
    res = floor(log10(p) + 1);
    cout << "Result is " << res << endl;
}