/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = arr[0];
        int maxEnding = arr[0];
        for (int i = 1; i < (int)(arr.size()); i++)
        {
            maxEnding = max(arr[i], maxEnding + arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
};
// @lc code=end

