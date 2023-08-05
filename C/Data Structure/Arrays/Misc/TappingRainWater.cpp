#include<bits/stdc++.h>
using namespace std;
int TappingRainWater(int arr[], int n){
    // O(n) time complexity
    int left[n];
    int right[n];
    int i,j;
    left[0]=arr[0];
    for(i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
    int water=0;
    for(i=0;i<n;i++){
        water+=min(left[i],right[i])-arr[i];
    }
    return water;
}

int TappingRainWater2(int arr[], int n){
    // O(n*n) time complexity
    int res = 0;
    for (int i = 1; i < n - 1; i++){
        int lMax = arr[i];
        for (int j = 0; j < i; j++){
            lMax = max(lMax, arr[j]);
        }
        int rMax = arr[i];
        for (int j = i+1; j < n; j++){
            rMax = max(rMax, arr[j]);
        }
        res = res + min(lMax, rMax) - arr[i];
    }
    return res;
}