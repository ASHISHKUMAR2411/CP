// You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.Return any valid arrangement of pairs.
// Note: The inputs will be generated such that there exists a valid arrangement of pairs.

// Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
// Output : [ [ 11, 9 ], [ 9, 4 ], [ 4, 5 ], [ 5, 1 ] ] 

#include<bits/stdc++.h>
    using namespace std;

vector<vector<int>> validArrangement(vector<vector<int>> & pairs){
    vector<int> arr;
    vector<vector<int>> ans;
    for(int i=0;i<pairs.size();i++){
        arr.push_back(pairs[i][0]);
        arr.push_back(pairs[i][1]);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(i%2==0){
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[i+1]);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> pairs = {{5,1},{4,5},{11,9},{9,4}};
    vector<vector<int>> ans = validArrangement(pairs);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// vector<vector<int>> validArrangement(vector<vector<int>> &pairs){
//     vector<vector<int>> result;
//     int n = pairs.size();
//     vector<int> visited(n, 0);
//     for(int i = 0; i < n; i++){
//         if(visited[i] == 0){
//             vector<int> temp;
//             temp.push_back(pairs[i][0]);
//             temp.push_back(pairs[i][1]);
//             result.push_back(temp);
//             visited[i] = 1;
//             for(int j = 0; j < n; j++){
//                 if(visited[j] == 0 && pairs[j][0] == pairs[i][1]){
//                     vector<int> temp;
//                     temp.push_back(pairs[j][0]);
//                     temp.push_back(pairs[j][1]);
//                     result.push_back(temp);
//                     visited[j] = 1;
//                 }
//             }
//         }
//     }
//     return result;
// }
