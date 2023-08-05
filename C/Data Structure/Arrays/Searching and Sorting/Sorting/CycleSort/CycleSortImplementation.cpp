#include<bits/stdc++.h>
using namespace std;
// Cycle Sort is used when we want to use less memeory writes , Like EPROMs have less memeory writes and it gets affected after one use 
//! It is a famous question 

// this case is for when all elements are distinct
void CycleSort(vector<int> &arr){
    for (int cs = 0; cs < arr.size();cs++){
        int item = arr[cs];
        int pos = cs;
        for(int i = cs+1; i < arr.size() ; i++){
            if(arr[i] < item){
                pos++;
            }
        }
        swap(item, arr[pos]);
        while(pos!=cs){
            pos = cs;
            for(int i = cs+1;i<arr.size();i++){
                if(arr[i] < item){
                    pos++;
                }
            }
            swap(item, arr[pos]);
        }
    }
}
int main() {
    srand(time(0));
    vector<int> arr;
    int n = rand()%100;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand());
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    CycleSort(arr);
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}