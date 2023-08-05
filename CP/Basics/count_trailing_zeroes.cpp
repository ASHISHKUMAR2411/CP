#include<bits/stdc++.h>
using namespace std;
int count_trailing_zeroes(int n){
    int count = 0,p;
    p = 5;
    while(p <=n ){
        count += n / p;
        p  *= 5;
    }
    return count;
}
int main(){
    int n;
    cout<<"enter the number : ";
    cin >> n;
    cout << count_trailing_zeroes(n) << endl;
}