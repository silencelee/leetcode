/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (54.41%)
 * Likes:    841
 * Dislikes: 46
 * Total Accepted:    149.1K
 * Total Submissions: 273.5K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(int k, int n, vector<vector<int>>& res, vector<int>& path, int cur)
    {
        if (path.size() == k && n == 0) {
            res.emplace_back(path);
            return;
        }

        if (n < 0) return;

        for (int i = cur; i <= 9; ++i) {
            path.emplace_back(i);
            dfs(k, n - i, res, path, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;

        dfs(k, n, res, path, 1);
        return res;
    }
};
// @lc code=end

