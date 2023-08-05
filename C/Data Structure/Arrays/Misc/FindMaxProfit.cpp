#include<bits/stdc++.h>
using namespace std;
int MaxProfit(int arr[] , int start , int end){
    if(end<= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++){
        for (int j = i + 1; j <= end; j++){
            if(arr[j]>arr[i]){
                int curr_profit = arr[j] - arr[i] + MaxProfit(arr,start , i-1) + MaxProfit(arr,j+1,end);
                profit = max(profit,curr_profit);
            }
        }
    }
    return profit;
}

int MaxProfit2(int arr[] , int n){
    int profit = 0;
    for (int i = 1; i < n;i++){
        if(arr[i] > arr[i-1]){
            profit += arr[i] - arr[i-1];
        }
    }
    return profit;
}

int main(){
    int arr[] = {1,2,3,4,5, 12, 3 , 1 , 3 ,4 , 5, 6, 7,5 ,3, 1, 3,45, 6, 7,8,12 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<MaxProfit(arr,0,n-1);
    return 0;
}