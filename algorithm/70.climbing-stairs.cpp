/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (46.18%)
 * Likes:    4119
 * Dislikes: 133
 * Total Accepted:    661.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        vector<int> f(n, 0);
        f[0] = 1;
        f[1] = 2;

        for (int i = 2; i < n; ++i) {
            f[i] = f[i - 2] + f[i - 1];    
        }

        return f[n - 1];
    }
};
// @lc code=end

