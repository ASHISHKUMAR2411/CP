// Finding the element's position with respect to the matrix considering it start from (0,0) and finding relative position of the element if found otherwise return (-1,-1) the invalid index Which is not possible

// Given Matrix is sorted RowWise and ColumnWise which means that every A(i,j) ≤ A(i+1,j) ∈ i+1 < No. of rows , And ColumnWise sorted  i.e A(i,j) ≤ A(i,j+1) ∈ j+1 < No. of columns,

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int ele){
    int low = 0, mid = 0 , high = arr.size() - 1;
    while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid] == ele)
            return mid;
        else if(arr[mid] < ele)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void print(vector<vector<int>> &arr)
{
    // this is not much cache friendly
    cout << "\n"
         << "-------------------------------"
         << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

pair<int,int> FindElementPosition(vector<vector<int>> &arr, int ele){
    int i = 0;
    while(i < arr.size()){
        if(ele > arr[i][0] && ele > arr[i][arr[i].size()-1])
            i++;
        else{
            int pos = binarySearch(arr[i], ele);
            if(pos == -1)
                i++;
            else
                return {i, pos};
        }
    }
    return {-1, -1};
}
bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}
void Sort(vector<vector<int>> &arr){
    // Column wise
    for (int i = 0; i < arr.size();i++){
        sort(arr[i].begin(), arr[i].end());
    }
    // Row Wise
    sort(arr.begin(), arr.end(), sortcol);
}
int main()
{
    srand(time(0));
    vector<vector<int>> arr;
    int n = rand() % 50, m = rand() % 50;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(rand()%100);
        }
        arr.push_back(v);
    }
    Sort(arr);
    print(arr);
    int ele = rand() % 250;
    cout<<"Element is "<<ele<<endl;
    pair<int,int> pos = FindElementPosition(arr, ele);
    if(pos.first == -1)
        cout<<"ELement Not Found"<<endl;
    else
        cout<<"Element found at "<<pos.first<<"  and "<<pos.second<<endl;
    return 0;
}