// FInding pair with GIven SUm but the array is sorted 
#include<bits/stdc++.h>
using namespace std;
// returning the index of the pair it takes O(n) time
pair<int,int> FindPairWithGivenSum(int arr[], int n, int sum){
    int low = 0, high = n - 1, sumPair = 0;
    while(low<high){
        sumPair = arr[low] + arr[high];
        if(sumPair == sum){
            return make_pair(low,high);
        }
        else if(sumPair < sum){
            low++;
        }
        else{
            high--;
        }
    }
    return make_pair(-1,-1);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    pair<int,int> p = FindPairWithGivenSum(arr, n, sum);
    if(p.first == -1 && p.second == -1)
        cout << "Pair not found";
    else
        cout << "Pair found at index " << p.first << " and " << p.second;
    return 0;
}