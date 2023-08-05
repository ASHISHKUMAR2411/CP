// In this  we merge the overlapping array
#include <bits/stdc++.h>
using namespace std;

// Using My Naive Solution
int MergeOverlappingRanges(vector<int> &Arrival,vector<int> &Departure)
{
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());
    int i = 1, curr = 1, res = 1, j = 0;
    while(i<(int)(Arrival.size()) && j < (int)(Departure.size())){
        if(Arrival[i] < Departure[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    return res;
}
int main()
{
    srand(time(0));
    int n = rand();
    vector<int> Arrival, Departure;
    for(int i = 0; i < n; i++){
        Arrival.push_back(rand()%3000);
        Departure.push_back(rand()%3000);
    }
    // vector<pair<int, int>> Ranges = {{1, 3}, {2, 4}, {5, 7}, {6, 8}, {3, 4}};
    cout << MergeOverlappingRanges(Arrival, Departure)<<endl;
    cout << endl;
    return 0;
}