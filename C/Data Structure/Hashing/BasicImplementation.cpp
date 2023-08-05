// Basic Implementation for Hash 
// unordered_set/unordered_map for hash
#include<bits/stdc++.h>
using namespace std;
void Delete(vector<bool> &arr, int i){
    arr[i] = 0;
    cout << i <<" Deleted" << endl;
}
void insert(vector<bool> &arr, int i){
    arr[i] = 1;
    cout << i <<" Inserted" << endl;
}
void search(vector<bool> &arr, int i){
    if(arr[i])
        cout << i<< " found"<<endl;
    else
        cout << i << " Not Found" << endl;
}
int main()
{
    vector<bool> arr(1000); // By Default 0 Value
    // bool arr[1000]; by Default Garbage Value
    // Inserting 111 , 789 , 536, 384 , 38 , 1
    insert(arr, 111);
    insert(arr, 789);
    insert(arr, 536);
    search(arr, 536);
    search(arr, 53);
    Delete(arr, 111);
    search(arr, 111);
    return 0;
}