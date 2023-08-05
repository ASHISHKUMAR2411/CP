#include <bits/stdc++.h>
using namespace std;
int MajorityELement(int arr[], int n)
{
    // using hash method i.e auxiliary space more in O(n) time complexity
    int hash[100001];
    for (int i = 0; i <= 1e5; i++)
    {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int ele = -1;
    for (int i = 0; i <= 1e5; i++)
    {
        if (hash[i] > n / 2)
        {
            ele = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

int MajorityELement2(int arr[], int n)
{
    // using hash method i.e auxiliary space more in O(n) time complexity
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    int ele = -1;
    for (auto i : hash)
    {
        if (i.second > n / 2)
        {
            ele = i.first;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

int majorityElement(int *arr, int n)
{
    // sort the array in O(nlogn)
    sort(arr, arr + n);

    int count = 1, max_ele = -1, temp = arr[0], ele, f = 0;

    for (int i = 1; i < n; i++)
    {
        // increases the count if the same element occurs
        // otherwise starts counting new element
        if (temp == arr[i])
        {
            count++;
        }
        else
        {
            count = 1;
            temp = arr[i];
        }

        // sets maximum count
        // and stores maximum occurred element so far
        // if maximum count becomes greater than n/2
        // it breaks out setting the flag
        if (max_ele < count)
        {
            max_ele = count;
            ele = arr[i];

            if (max_ele > (n / 2))
            {
                f = 1;
                break;
            }
        }
    }

    // returns maximum occurred element
    // if there is no such element, returns -1
    return (f == 1 ? ele : -1);
}

// naive solution O(n*n) method
int MajorityELement3(int arr[], int n)
{
    int res = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            res = i;
            break;
        }
    }
    return res;
}

int Candidate(int arr, int n){
    int maj_index = 0 , count = 1;
    for (int i = 1; i < n;i++){
        if(arr[maj_index] == arr[i]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}

bool isMajority(int arr[], int n , int candidate){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == candidate){
            count++;
        }
    }
    return count > n/2;
}
// using Moore's Voting Algorithm in O(n)
int MajorityELement4(int arr[], int n){
    int candidate = Candidate(arr, n);
    int ele = -1;
    if(isMajority(arr, n, candidate)){
        ele = candidate;
    }
    else return -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == candidate){
            return i;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1, 4, 5, 1, 4, 5, 6, 1, 1, 1, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MajorityELement2(arr, n);
    return 0;
}