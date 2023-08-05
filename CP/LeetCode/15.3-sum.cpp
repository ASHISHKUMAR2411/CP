/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        if(num.size() < 3)
        return vector<vector<int>>();
        sort(num.begin(), num.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < num.size() - 2; i++)
        {
            if (i == 0 || (i > 0 && num[i] != num[i - 1]))
            {
                int lo = i + 1, hi = num.size() - 1, sum = 0 - num[i];
                while (lo < hi)
                {
                    if (num[lo] + num[hi] == sum)
                    {
                        vector<int> p;
                        p.push_back(num[lo]);
                        p.push_back(num[hi]);
                        p.push_back(num[i]);
                        triplets.push_back(p);
                        while (lo < hi && num[lo] == num[lo + 1])
                            lo++;
                        while (lo < hi && num[hi] == num[hi - 1])
                            hi--;
                        lo++;
                        hi--;
                    }
                    else if (num[lo] + num[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return triplets;
    }
};
// @lc code=end

