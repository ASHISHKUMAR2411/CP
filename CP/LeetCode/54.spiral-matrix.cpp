/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &arr)
    {
        int n = (int)(arr.size()), m = (int)(arr[0].size());
        vector<int> l;
        for (int i = 0; i < (n - i); i++)
        {
            for (int j = i; j < (m - i); j++)
            {
                if (arr[i][j] == -1000)
                {
                    return l;
                }
                if ((int)(l.size()) == m * n)
                    return l;
                else
                    l.push_back(arr[i][j]);
                // cout << " " << arr[i][j];
                arr[i][j] = -1000;
            }
            for (int j = i + 1; j < (n - i); j++)
            {
                if (arr[j][m - i - 1] == -1000)
                {
                    return l;
                }
                if ((int)(l.size()) == m * n)
                    return l;
                else
                    l.push_back(arr[j][m - i - 1]);
                // cout << " " << arr[j][m - i - 1];
                arr[j][m - i - 1] = -1000;
            }
            for (int j = (m - 2 - i); j >= i; j--)
            {
                if (arr[n - i - 1][j] == -1000)
                {
                    return l;
                }
                if ((int)(l.size()) == m * n)
                    return l;
                else
                    l.push_back(arr[n - i - 1][j]);
                // cout << " " << arr[n - i - 1][j];
                arr[n - i - 1][j] = -1000;
            }
            for (int j = n - 2 - i; j > i; j--)
            {
                if (arr[j][i] == -1000)
                {
                    return l;
                }
                if ((int)(l.size()) == m * n)
                    return l;
                else
                    l.push_back(arr[j][i]);
                // cout << " " << arr[j][i];
                arr[j][i] = -1;
            }
        }
        return l;
    }
};
// @lc code=end

