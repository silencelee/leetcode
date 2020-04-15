/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.00%)
 * Likes:    3528
 * Dislikes: 259
 * Total Accepted:    532.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
    {
        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> res;
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                vector<int> seg;
                seg.emplace_back(start);
                seg.emplace_back(end);
                res.emplace_back(seg);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        vector<int> seg;
        seg.emplace_back(start);
        seg.emplace_back(end);
        res.emplace_back(seg);
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        auto my_cmp = [](const vector<int>& v1, const vector<int>& v2)
        {
            if (v1[0] < v2[0]) {
                return true;
            } else if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }

            return false;
        };

        sort(intervals.begin(), intervals.end(), my_cmp);
        
        res = merge_intervals(intervals);
        return res;
    }
};
// @lc code=end

