/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (41.45%)
 * Likes:    256
 * Dislikes: 16
 * Total Accepted:    12.5K
 * Total Submissions: 29.7K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an N x N grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized and return the distance.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * If no land or water exists in the grid, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: 
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: 
 * The cell (2, 2) is as far as possible from all the land with distance
 * 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct Point {
        int x;
        int y;
    };
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        queue<Point> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int x = p.x + dx[i];
                int y = p.y + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (dist[x][y] > dist[p.x][p.y] + 1) {
                    dist[x][y] = dist[p.x][p.y] + 1;
                    q.push({x, y});
                }
            }
        }
        
        int res = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) res = max(res, dist[i][j]);
            }
        }
        return res == INT_MAX ? - 1 : res;
    }
};
// @lc code=end

