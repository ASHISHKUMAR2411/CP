/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        if (arr.size() < 4)
            return res;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < (int)(arr.size()) - 3; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < (int)(arr.size()) - 2; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int lo = j + 1, hi = (int)(arr.size()) - 1, sum = target - arr[i] - arr[j];
                while (lo < hi)
                {
                    if (arr[lo] + arr[hi] == sum)
                    {
                        vector<int> p;
                        p.push_back(arr[i]);
                        p.push_back(arr[j]);
                        p.push_back(arr[lo]);
                        p.push_back(arr[hi]);
                        res.push_back(p);
                        while (lo < hi && arr[lo] == arr[lo + 1])
                            lo++;
                        while (lo < hi && arr[hi] == arr[hi - 1])
                            hi--;
                        lo++;
                        hi--;
                    }
                    else if (arr[lo] + arr[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

