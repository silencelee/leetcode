/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (31.10%)
 * Likes:    4477
 * Dislikes: 163
 * Total Accepted:    351.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int f = nums[0];
        int g = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int a = nums[i];
            int fa = f * a;
            int ga = g * a;
            f = max(a, max(fa, ga));
            g = min(a, min(fa, ga));

            res = max(res, f);
        }

        return res;
    }
};
// @lc code=end

