// In this  we merge the overlapping array
#include <bits/stdc++.h>
using namespace std;

// Using My Naive Solution
void MergeOverlappingRanges(vector<pair<int, int>> &Ranges)
{
    sort(Ranges.begin(), Ranges.end());
    cout << endl
         << endl
         << endl;
    for (auto it : Ranges)
    {
        cout << "{" << it.first << "," << it.second << "} ";
    }
    cout << endl
         << endl;
    int i = 0;
    while (i < (int)(Ranges.size() - 1))
    {
        if (Ranges[i].second >= Ranges[i + 1].first )
        {
            Ranges[i].first = min(Ranges[i].first, Ranges[i + 1].first);
            Ranges[i].second = max(Ranges[i].second, Ranges[i + 1].second);
            Ranges.erase(Ranges.begin() + i + 1);
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    // int n = 25;
    // int arr[n];
    // srand(time(0));
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = rand();
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    srand(time(0));
    int n = rand()%100,n1,n2;
    vector<pair<int, int>> Ranges;
    for (int i = 0; i < n; i++){
        n1 = rand();
        n2 = rand();
        if(n1> n2)
        Ranges.push_back({n2,n1});
        else
        Ranges.push_back({n1,n2});
    }
    // vector<pair<int, int>> Ranges = {{1, 3}, {2, 4}, {5, 7}, {6, 8}, {3, 4}};
    for (auto it : Ranges)
    {
        cout << "{" << it.first << "," << it.second << "} ";
    }
    cout<< endl<<endl<<endl;
    MergeOverlappingRanges(Ranges);
    for (auto it : Ranges)
    {
        cout << "{" << it.first << "," << it.second << "} ";
    }
    cout << endl;
    return 0;
}