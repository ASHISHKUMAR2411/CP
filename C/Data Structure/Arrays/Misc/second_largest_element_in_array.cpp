#include<bits/stdc++.h>
using namespace std;
int second_largest_element_in_array(int arr[] , int n){
    int i, max = arr[0], second_max = -1;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            second_max = max;
            max = arr[i];
        }
        else if (arr[i] > second_max && arr[i] != max)
            second_max = arr[i];
    }
    return second_max;
}
int main()
{
    int arr[] = {12, 34, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Second largest element is " << second_largest_element_in_array(arr, n);
    return 0;
}
