// find the next greater element
#include <bits/stdc++.h>
using namespace std;

vector<int> NextGreater(const vector<int> &arr)
{
    vector<int> next(arr.size());
    stack<int> st;
    st.push(arr.size() - 1);
    next[arr.size() - 1] = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            while (st.empty() == false)
            {
                int it = st.top();
                if (arr[it] > arr[i])
                {
                    next[i] = arr[it];
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(st.empty())
                next[i] = -1;
            st.push(i);
        }
        else
        {
            next[i] = arr[i + 1];
        }
    }
    return next;
}

vector<int> NextGreatest(vector<int> &arr)
{
    vector<int> next(arr.size());
    next[arr.size() - 1] = -1;
    int max = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            next[i] = -1;
            max = arr[i];
        }
        else
        {
            next[i] = max;
        }
    }
    return next;
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
    arr1 = NextGreater(arr);
    for (int i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;
    arr1 = NextGreatest(arr);
    for (int i : arr1)
    {
        cout << i << " ";
    }
    return 0;
}