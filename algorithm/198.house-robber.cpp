/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.57%)
 * Likes:    3853
 * Dislikes: 119
 * Total Accepted:    446.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */

// @lc code=start
 
// f[i] means not rob house i
// g[i] means rob house i
// f[i] = max(f[i - 1], g[i - 1]) if not rob house i
// g[i] = f[i - 1] + nums[i]  if rob house i
// result = max(f[i], g[i])
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        vector<int> g(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            f[i] = max(f[i - 1], g[i - 1]);
            g[i] = f[i - 1] + nums[i - 1];
        }

        return max(f[n], g[n]);  
    }
};
// @lc code=end

