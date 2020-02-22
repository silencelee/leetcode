/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (40.63%)
 * Likes:    1370
 * Dislikes: 82
 * Total Accepted:    164.1K
 * Total Submissions: 401.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool cell[3][3][9] = {false};

    bool dfs(vector<vector<char>>& board, int x, int y)
    {
        if (y == 9) {
            y = 0;
            ++x;
        }

        if (x == 9) return true;
        if (board[x][y] != '.') return dfs(board, x, y + 1);

        for (int i = 0; i < 9; ++i) {
            if (!row[x][i] && !col[i][y] && !cell[x / 3][y / 3][i]) {
                row[x][i] = col[i][y] = cell[x / 3][y / 3][i] = true;
                board[x][y] = '1' + i;
                if (dfs(board, x, y + 1)) return true;
                row[x][i] = col[i][y] = cell[x / 3][y / 3][i] = false;
                board[x][y] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int t = board[i][j] - '1';

                row[i][t] = true;
                col[t][j] = true;
                cell[i / 3][j / 3][t] = true;
            }
        }

        dfs(board, 0, 0);
    }
};
// @lc code=end

