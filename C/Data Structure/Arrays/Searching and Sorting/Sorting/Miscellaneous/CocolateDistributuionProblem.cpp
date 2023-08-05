// Given m childrens and n Packets of Chocolate where n>=m and we have to distribute 1 Packets to each children such that the difference between the number of chocolate of minimum and maximum  is minimum , find the difference here arr[i] represents the numbers of chocolate in ith packet
#include<bits/stdc++.h>
using namespace std;
int FindMinimumDifference(int arr[],int n,int m)
{
    if(n<m)
        return -1;
    sort(arr,arr+n);
    int res = INT_MAX;
    for (int i = 0; i + m - 1 < n;i++){
        res = min(res, (arr[m + i - 1] - arr[i]));
    }
    return res;
}
int main()
{
    int n = 25;
    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;
    int m;
    cout << "Enter the number of childrens : ";
    cin >> m;
    if(m>n)
        cout << "Distribution is not possible." << endl;
    else
        cout << "The minimum difference is : " << FindMinimumDifference(arr, n, m) << endl;
    return 0;
}