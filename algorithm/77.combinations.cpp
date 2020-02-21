/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (51.82%)
 * Likes:    1162
 * Dislikes: 59
 * Total Accepted:    256K
 * Total Submissions: 492.5K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(int n, int k, vector<vector<int>>& res, vector<int>& path, int cur)
    {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = cur; i <= n; ++i) {
            path.emplace_back(i);
            dfs(n, k, res, path, i + 1);
            path.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;

        dfs(n, k, res, path, 1); 
        return res;
    }
};
// @lc code=end

