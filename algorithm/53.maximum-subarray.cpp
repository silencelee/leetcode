/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.56%)
 * Likes:    6446
 * Dislikes: 284
 * Total Accepted:    793.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int last = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int now = max(last, 0) + nums[i];
            res = max(res, now);
            last = now;
        }

        return res;
    }
};
// @lc code=end

