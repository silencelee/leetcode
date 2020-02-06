/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (25.10%)
 * Likes:    1154
 * Dislikes: 534
 * Total Accepted:    182.5K
 * Total Submissions: 724.9K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        int r = board.size();
        int c = board[0].size();

        if (x < 0 || x >= r || y < 0 || y >= c || board[x][y] != 'O') return; 
        board[x][y] = '$';

        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < c; ++i) {
            if (board[0][i] == 'O') dfs(board, 0, i);
            if (board[r - 1][i] == 'O') dfs(board, r - 1, i);
        }

        for (int i = 0; i < r; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][c - 1] == 'O') dfs(board, i, c - 1);
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';      
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end

