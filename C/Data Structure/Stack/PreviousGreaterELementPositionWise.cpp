// Find Previous greater ELement in the array position wise 
// for ex {15,10,18,12} ans is {-1,15,-1,18} 
#include <bits/stdc++.h>
using namespace std;
vector<int> PreviousGreaterELementPositionWise(vector<int> &arr)
{
    vector<int> span;
    stack<pair<int, int>> Stack;
    if (arr.size() == 1)
        return {-1};
    Stack.push({arr[0], 0});
    span.push_back(-1);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            while (Stack.empty() == false)
            {
                auto it = Stack.top();
                if (it.first > arr[i])
                {
                    break;
                }
                else
                {
                    Stack.pop();
                }
            }
            if (Stack.empty())
            {
                span.push_back(-1);
            }
            else
            {
                auto it = Stack.top();
                span.push_back(it.first);
            }
        }
        else
        {
            Stack.push({arr[i - 1], i - 1});
            span.push_back(arr[i-1]);
        }
    }
    return span;
}

int main()
{
    srand(time(0));
    int n = rand() % 50;
    vector<int> arr, arr1;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 100);
    }
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    arr1 = PreviousGreaterELementPositionWise(arr);
    for (int i : arr1)
    {
        cout << i << " ";
    }
    return 0;
}