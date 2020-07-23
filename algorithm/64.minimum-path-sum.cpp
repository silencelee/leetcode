/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (50.98%)
 * Likes:    3096
 * Dislikes: 64
 * Total Accepted:    426.2K
 * Total Submissions: 786.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        vector<vector<int>> f(n, vector<int>(m, 0));
        f[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) f[i][0] = f[i - 1][0] + grid[i][0];
        for (int j = 1; j < m; ++j) f[0][j] = f[0][j - 1] + grid[0][j];

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }

        return f[n - 1][m - 1];        
    }
};
// @lc code=end

