/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>> &m)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        // vector<vector<int>> V;
        int n = m.size();
        reverse(m.begin(), m.end());
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = i + 1; j < m.size(); j++)
            {
                swap(m[i][j], m[j][i]);
            }
        }
    }
};
// @lc code=end

