/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (45.60%)
 * Likes:    2320
 * Dislikes: 81
 * Total Accepted:    137K
 * Total Submissions: 295.7K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> f(n, 0);
        vector<int> g(n, 0);
        g[0] = -prices[0];

        for (int i = 1; i < n; ++i) {
            f[i] = max(f[i - 1], g[i - 1] + prices[i]);

            if (i > 1) {
                g[i] = max(g[i - 1], f[i - 2] - prices[i]);
            } else {
                g[i] = max(g[i - 1], -prices[i]);
            }
        }

        return f[n - 1];
    }
};
// @lc code=end

