/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (48.24%)
 * Likes:    1462
 * Dislikes: 56
 * Total Accepted:    98.5K
 * Total Submissions: 198.1K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are some spherical balloons spread in two-dimensional space. For each
 * balloon, provided input is the start and end coordinates of the horizontal
 * diameter. Since it's horizontal, y-coordinates don't matter, and hence the
 * x-coordinates of start and end of the diameter suffice. The start is always
 * smaller than the end.
 * 
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps traveling up infinitely.
 * 
 * Given an array points where points[i] = [xstart, xend], return the minimum
 * number of arrows that must be shot to burst all balloons.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[10,16],[2,8],[1,6],[7,12]]
 * Output: 2
 * Explanation: One way is to shoot one arrow for example at x = 6 (bursting
 * the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the
 * other two balloons).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,2],[3,4],[5,6],[7,8]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: points = [[1,2],[2,3],[3,4],[4,5]]
 * Output: 2
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: points = [[1,2]]
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: points = [[2,3],[2,3]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= points.length <= 10^4
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };

        sort(points.begin(), points.end(), cmp);

        int res = 1;
        int end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                ++res;
                end = points[i][1];
            }
        }

        return res;
    }
};
// @lc code=end
