/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (43.47%)
 * Likes:    1451
 * Dislikes: 64
 * Total Accepted:    178.7K
 * Total Submissions: 409.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValidPos(vector<int>& pos, int row, int col)
    {
        for (int i = 0; i < row; ++i) {
            if (pos[i] == col) return false;
            if (abs(i - row) == abs(pos[i] - col)) return false;
        }

        return true;
    }

    void dfs(vector<vector<string>>& res, vector<int>& pos, int row)
    {
        int n = pos.size();
        if (row == n) {
            vector<string> path;
            for (int i = 0; i < n; ++i) {
                string s(n, '.');
                s[pos[i]] = 'Q';
                path.emplace_back(s);
            }
            
            res.emplace_back(path);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!isValidPos(pos, row, col))
                continue;
            pos[row] = col;
            dfs(res, pos, row + 1);
            pos[row] = -1;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return {};

        vector<vector<string>> res;
        vector<int> pos(n, -1);
        dfs(res, pos, 0);
        return res;
    }
};
// @lc code=end

