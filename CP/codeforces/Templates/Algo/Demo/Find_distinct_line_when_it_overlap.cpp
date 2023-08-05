#include<bits/stdc++.h>
using namespace std;
#define ll long long

multiset<pair<ll,ll>> mp;

void insert(ll l, ll r){
    // we need to solve three cases when the line overlap from left 
    // so we find the next previous line and check whether it overlap with the new coordinate
    auto it = mp.lower_bound({l, -1e18});
    if(it != mp.begin()){
        it--;
        if(it->second >= r){
            return;
        }
        if(it->first < l){
            l = it->first;
            mp.erase(it);
        }
    }

    // now for the lines overlapping in the right.
    it = mp.upper_bound({r, 1e18});
    if(it!=mp.begin()){
        it--;
        if(it->second >= r){
            r = it->second;
            mp.erase(it);
        }
    }

    // removing all the elements which lies over the line 
    while (1)
    {
        auto it = mp.lower_bound({l, -1e18});
        if(it != mp.end()){
            if(it->first > r){
                break;
            }
            else{
                mp.erase(it);
            }
        }
    }
    
}

int distinct_lines(){
    return mp.size();
}

