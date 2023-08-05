// Finding the minimum and maximum element in the array
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{2,4,5,6,3,2,4,5,7,9,8};
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());
    cout << " min : " << min << " max : " << max;
    return 0;
}