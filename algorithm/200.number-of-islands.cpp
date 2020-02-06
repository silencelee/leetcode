/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (44.47%)
 * Likes:    4022
 * Dislikes: 148
 * Total Accepted:    535.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == '0') return;

        grid[x][y] = '0';

        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int r = grid.size();
        int c = grid[0].size();

        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '0') continue;

                ++res;
                dfs(grid, i, j);
            }
        }
        
        return res;
    }
};
// @lc code=end

