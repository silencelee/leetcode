/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (27.46%)
 * Likes:    1441
 * Dislikes: 91
 * Total Accepted:    127.7K
 * Total Submissions: 458.5K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxProfit2(vector<int>& prices)
    {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) res += (prices[i] - prices[i - 1]);
        }

        return res;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        if (k >= n / 2) return maxProfit2(prices);

        int f[n + 1][k + 1][2];
        memset(f, -0x3f, sizeof(f));
        for (int i = 0; i <= n; ++i) f[i][0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
            }
        }

        int res = 0;
        for (int i = 0; i <= k; ++i) res = max(res, f[n][i][0]);
        return res;
    }
};
// @lc code=end

