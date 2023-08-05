// In this we are going to convert the 2d array into 1d array.
#include<bits/stdc++.h>
using namespace std;

class Flatten{
    public:
        vector<vector<int>::iterator> Start;
        vector<vector<int>::iterator> End;
        int currIndex;
        int n;
        Flatten(vector<vector<int>> &v){
            n = v.size();
            Start.resize(n);
            End.resize(n);
            currIndex = 0;
            for(int i = 0; i < n; i++){
                Start[i] = v[i].begin();
                End[i] = v[i].end();
            }
        }
        bool hasNext(){
            for (int i = 0; i < n; i++){
                if(Start[i] != End[i]){
                    return true;
                }
            }
            return false;
        }
        int next(){
            if(Start[currIndex] == End[currIndex]){
                currIndex++;
                return next();
            }
            else{
                return *Start[currIndex]++;
            }
        }
};

int main(){
    vector<vector<int>> arr{{1, 2, 3}, {3, 4, 5}, {6, 7}, {8, 9, 10, 11}};
    Flatten item(arr);
    while(item.hasNext()){
        cout<<item.next()<<" ";
    }
    return 0;
}