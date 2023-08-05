// In this we are going to learn more about vectors functionality i.e usage
#include<bits/stdc++.h>
using namespace std;

void Print(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> p;
    // 1.1 assign(size_type n, const value_type g) – Assigns new content to vector and resize
    p.assign(5,10); // it will assign 5 element with value 10
    vector<int>::iterator it;
    it = p.begin() + 1;
    vector<int> q;
    // 1.2 assign(input_iterator first, input_iterator last) – Assigns new content to vector and resize
    q.assign(it, p.end() - 1);

    int arr[] = {1, 2, 4};
    vector<int> r;
    r.assign(arr, arr + (int)(sizeof(arr)/sizeof(arr[0])));
    Print(p);
    Print(q);
    Print(r);
}