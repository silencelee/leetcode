/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (38.37%)
 * Likes:    1145
 * Dislikes: 100
 * Total Accepted:    73.5K
 * Total Submissions: 189.8K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        using PII = pair<int, int>;
        int n = matrix.size();
        int m = matrix[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<PII> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];

                if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) continue;
                
                dist[x][y] = dist[p.first][p.second] + 1;
                visited[x][y] = true;

                q.push({x, y});
            }
        }

        return dist;
    }
};
// @lc code=end

