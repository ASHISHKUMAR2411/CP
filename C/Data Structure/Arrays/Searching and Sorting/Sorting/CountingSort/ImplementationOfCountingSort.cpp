// The reason why we use Count sort is because it takes O(n+k) time complexity But there are certain criteria to use them , where k is the range of possible element we can have in array , so for the our K should be proportional to n so that it takes linear time for sorting

// The basic Idea Behind Count Sort is that we create a dummy array to store the count of element, at index as element, and we use another array to store how many element are there the particular element which give an idea where to put the element as it ensures the Stability when we traverse from behind

// Disadvantages are : it is not useful when k is large , we use Radix Sort where range of element is K which is not very large but the Range lies in larger number, i.e if k = n*n then time complexity become n*n i.e totally depend on value on k , but this is not the case with radix sort   

// Space Complexity : O(n+k) 
// Time Complexity : O(n+k)
#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
    // Cumulative Count Array
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void printArray(vector<int> &arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    srand(time(0));
    vector<int> arr;
    int n = rand() % 1000;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % n);
    }
    printArray(arr);
    countSort(arr);
    printArray(arr);
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// void CountSort(vector<int> &arr, int k)
// {
//     vector<int> Count(k, 0);
//     for (int i = 0; i < arr.size(); i++)
//     {
//         Count[arr[i]]++;
//     }
//     for (int i = 1; i < k; i++)
//         Count[i] += Count[i - 1];
//     vector<int> Sort(arr.size());
//     for (int i = arr.size() - 1; i >= 0; i++)
//     {
//         Sort[Count[arr[i]] - 1] = arr[i];
//         Count[arr[i]]--;
//     }
//     arr = Sort;
// }
// int main()
// {
//     srand(time(0));
//     vector<int> arr;
//     int n = rand() % 300;
//     int k = rand() % 600;
//     for (int i = 0; i < n; i++)
//     {
//         arr.push_back(rand() % k);
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     cout << endl;
//     CountSort(arr, k);
//     for (int i = 0; i < n ; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }