/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (55.32%)
 * Likes:    388
 * Dislikes: 135
 * Total Accepted:    120.1K
 * Total Submissions: 216.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValidPos(vector<int>& pos, int row, int col)
    {
        for (int i = 0; i < row; ++i) {
            if ((pos[i] == col) || (abs(i - row) == abs(pos[i] - col))) {
                return false;
            }
        }
        return true;
    }

    void dfs(int& res, vector<int>& pos, int row)
    {
        int n = pos.size();
        if (row == n) {
            ++res;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!isValidPos(pos, row, col)) continue;
            pos[row] = col;
            dfs(res, pos, row + 1);
            pos[row] = -1;
        }
    }

    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        dfs(res, pos, 0);

        return res;
    }
};
// @lc code=end

