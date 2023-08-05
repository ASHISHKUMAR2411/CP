// Binary Lifting 

#include<bits/stdc++.h>
using namespace std;
int findI(vector<int> &startIndex, int i, int &k, vector<vector<int>> &binaryLifting){
    int start = i;

    // for(int j = 1; j <= k and start > -1 ; j++){
    //     start = startIndex[start];
    // }
    for(int j = 20; j >= 0 and start > -1 ; j--){
        int mask = 1 << j;
        if((mask&k) > 0){
            start = binaryLifting[j][start];
        }
    }
    return i - start;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, s;
        cin >> n >> k >> s;
        int arr[n];
        vector<int> startIndex(n);
        int j = 0, sum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
            while(sum > s){
                sum -= arr[j];
                j++;
            }
            startIndex[i] = j - 1;
        }
        vector<vector<int>> binaryLifting(20, vector<int>(n, 0));
        binaryLifting[0] = startIndex;
        for(int i = 1; i < 20; i++){
            for(int j = 0; j < n; j++){
                int parent = binaryLifting[i-1][j];
                binaryLifting[i][j] = parent == -1 ? parent : binaryLifting[i - 1][parent];
            }
        }
        // startIndex will store the index of the last element of the segment. 
        int maix = 0; 
        for(int i = n-1; i >= 0; i--){
            maix = max(maix, findI(startIndex, i, k, binaryLifting));
        }
        cout << maix << endl;
    }
}