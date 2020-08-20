/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (57.07%)
 * Likes:    628
 * Dislikes: 528
 * Total Accepted:    64.2K
 * Total Submissions: 108.6K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();

        using PII = pair<int, int>;
        int x = click[0];
        int y = click[1];

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<PII> q;
        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int a = t.first;
            int b = t.second;

            char cnt = '0';
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) continue;
                    int nx = a + i;
                    int ny = b + j;
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

                    if (board[nx][ny] == 'M') ++cnt;
                }
            }

            if (cnt == '0') {
                board[a][b] = 'B';
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i == 0 && j == 0) continue;
                        int nx = a + i;
                        int ny = b + j;
                    
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            } else {
                board[a][b] = cnt;
            }
        }

        return board;
    }
};
// @lc code=end

