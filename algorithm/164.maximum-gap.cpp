/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 *
 * https://leetcode.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (34.36%)
 * Likes:    996
 * Dislikes: 196
 * Total Accepted:    95.4K
 * Total Submissions: 262.4K
 * Testcase Example:  '[3,6,9,1]'
 *
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * 
 * Return 0 if the array contains less than 2 elements.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,6,9,1]
 * Output: 3
 * Explanation: The sorted form of the array is [1,3,6,9], either
 * (3,6) or (6,9) has the maximum difference 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [10]
 * Output: 0
 * Explanation: The array contains less than 2 elements, therefore return 0.
 * 
 * Note:
 * 
 * 
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * Try to solve it in linear time/space.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct Range {
        int min;
        int max;
        bool used;

        Range(): min(INT_MAX), max(INT_MIN), used(false) {}
    };

    int maximumGap(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }

        int n = nums.size();
        if (n < 2 || min_val == max_val) return 0;

        int len = (max_val - min_val + n - 2) / (n - 1);
        vector<Range> range(n - 1);

        for (int x : nums) {
            if (x == min_val) continue;
            int k = (x - min_val - 1) / len;

            range[k].min = min(range[k].min, x);
            range[k].max = max(range[k].max, x);
            range[k].used = true;
        }

        int res = 0;
        int last = min_val;
        for (auto& r : range) {
            if (!r.used) continue;
            res = max(res, r.min - last);
            last = r.max;
        }

        return res;
    }
};
// @lc code=end
