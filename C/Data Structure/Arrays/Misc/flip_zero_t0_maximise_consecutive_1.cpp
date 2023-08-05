#include<bits/stdc++.h>
using namespace std;
// flip k 0s to make maximum consecutive 1s
int longestOnes(vector<int> &nums, int k)
{
    if (k == (int)(nums.size()))
    {
        return k;
    }
    vector<pair<int, int>> oz;
    int count = 0;
    for (int i = 0; i < (int)(nums.size()); i++)
    {
        if (nums[i])
        {
            while (i < (int)(nums.size()) && nums[i] == 1)
            {
                count++;
                i++;
            }
            i--;
            oz.push_back({1, count});
            count = 0;
        }
        else
        {
            while (i < (int)(nums.size()) && nums[i] == 0)
            {
                count++;
                i++;
            }
            i--;
            oz.push_back({0, count});
            count = 0;
        }
    }
    // for(int i = 0; i<(int)(oz.size()); i++){
    //     cout<<oz[i].first<<" "<<oz[i].second<<endl;
    // }
    int maxi = 0, ki = k, j;
    count = 0;
    for (int i = 0; i < (int)(oz.size()); i++)
    {
        ki = k;
        count = 0;
        for (j = i; j < (int)(oz.size()); j++)
        {
            // if(ki == 0) break;
            if (count == 0 && oz[j].first == 0)
            {
                if (oz[i].second > ki)
                {
                    count += ki;
                    ki = 0;
                }
                else
                {
                    count += oz[j].second;
                    ki -= oz[j].second;
                }
            }
            else if (oz[j].first == 0)
            {
                if (oz[j].second > ki)
                {
                    count += ki;
                    ki = 0;
                    break;
                }
                else
                {
                    count += oz[j].second;
                    ki -= oz[j].second;
                }
            }
            else
            {
                count += oz[j].second;
            }
        }
        if (i > 0 && oz[i - 1].first == 0 && oz[i - 1].second > ki && j == (int)(oz.size()) && ki != 0)
            count += ki;
        if (maxi < count)
        {
            maxi = count;
            // cout<<maxi<<endl;
        }
    }
    return maxi;
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout<<longestOnes(nums, 2)<<endl;
    return 0;
}

