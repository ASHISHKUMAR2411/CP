// find the square root or floor of the square root of the number which using inbuilt function
#include<bits/stdc++.h>
using namespace std;
int SquareRootX(int n){
    int low = 1, high = n, ans = 0, mid = 0, midSqr  = 0;
    while(low<=high){
        mid = low + (high - low)/2;
        midSqr = mid*mid;
        if(midSqr == n) return mid;
        else if(midSqr > n){
            high = mid -1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n = 100;
    cout << "Square root of " << n << " is " << SquareRootX(n);
    return 0;
}