/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.22%)
 * Likes:    1565
 * Dislikes: 6296
 * Total Accepted:    335.5K
 * Total Submissions: 2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Note:
 * 
 * 
 * Assume we are dealing with an environment that could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For this
 * problem, assume that your function returns 2^31 − 1 when the division result
 * overflows.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: dividend = 0, divisor = 1
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: dividend = 1, divisor = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 * 
 * 
 */

// @lc code=start

class Solution {
public:
    int divide(int dividend, int divisor) {
        using LL = long long;
        bool is_minus = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) is_minus = true;
        
        LL x = abs(LL(dividend));
        LL y = abs(LL(divisor));
        
        vector<LL> exp;
        for (LL i = y; i <= x; i = i + i) {
            exp.emplace_back(i);
        }
        
        LL res = 0;
        for (int i = exp.size() - 1; i >= 0; --i) {
            if (x >= exp[i]) {
                x -= exp[i];
                res += 1LL << i;
            }
        }
        
        if (is_minus) res = -res;
        if (res < INT_MIN || res > INT_MAX) res = INT_MAX;
        return res;
    }
};

// @lc code=end

