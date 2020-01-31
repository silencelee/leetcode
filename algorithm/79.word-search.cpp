/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.43%)
 * Likes:    2709
 * Dislikes: 137
 * Total Accepted:    383.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited)
    {
        if (index == word.size()) return true;

        int m = board.size();
        int n = board[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[index] || visited[x][y]) return false;
        visited[x][y] = true;

        bool ret = dfs(board, word, index + 1, x - 1, y, visited) || // up
                   dfs(board, word, index + 1, x + 1, y, visited) || // down
                   dfs(board, word, index + 1, x, y - 1, visited) || // left
                   dfs(board, word, index + 1, x, y + 1, visited);   // right

        visited[x][y] = false;
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, visited)) return true;      
            }
        }

        return false;
    }
};
// @lc code=end

