// For finding the lower bound in vector which means the first value which is not less than the given value and upper bound is the value which is greater than the given value
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> p{20, 10, 40, 30};
    for(int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    auto lower = lower_bound(p.begin(), p.end(), 10);
    auto upper = upper_bound(p.begin(), p.end(), 30);
    cout << " position are "<< lower - p.begin() << " "<< upper - p.begin() << endl;
}