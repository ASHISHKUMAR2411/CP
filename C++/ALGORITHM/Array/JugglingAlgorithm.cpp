// This algorithm is used for array rotation 

#include<bits/stdc++.h>
using namespace std;

// It divide the into n/d segments and then move respective element one segment before (for left rotation) and one segment after( for right rotation) and similarly till d elements i.e for all the elements in the segment.
void jugglingAlgorithm(vector<int> &arr, int rotate){
    
}

int main(){
    srand(time(NULL));
    int n = rand()%100 + 1;
    vector<int> arr(n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    int rotation = rand() % n;
    jugglingAlgorithm(arr, rotation);
    cout << "\n After Rotation \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}