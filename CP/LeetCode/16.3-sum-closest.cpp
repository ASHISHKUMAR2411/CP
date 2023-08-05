/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = (int)(nums.size());
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++)
        {
            int lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target)
                    return target;
                if (abs(sum - target) < abs(res - target))
                    res = sum;
                if (sum < target)
                    lo++;
                else
                    hi--;
            }
        }
        return res;
    }
};
// @lc code=end
