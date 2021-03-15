/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.77%)
 * Likes:    2806
 * Dislikes: 599
 * Total Accepted:    404.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>> st(m, vector<bool>(n, false));

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;
        int x = 0;
        int y = 0;

        vector<int> res;
        for (int i = 0; i < m * n; ++i) {
            res.emplace_back(matrix[x][y]);
            st[x][y] = true;

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || st[nx][ny]) {
                dir = (dir + 1) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            x = nx;
            y = ny;
        }

        return res;
    }
};
// @lc code=end

