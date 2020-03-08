/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (33.43%)
 * Likes:    3111
 * Dislikes: 104
 * Total Accepted:    325.4K
 * Total Submissions: 966.1K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
// dfs TLE
/*
class Solution {
public:
    void dfs(vector<int>& coins, int cap, int& res, int cur, int start)
    {
        if (cap == 0) {
            res = min(res, cur);
            return;
        }
        if (cap < 0) return;

        for (int i = start; i < coins.size(); ++i) {
            dfs(coins, cap - coins[i], res, cur + 1, i);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;

        sort(coins.rbegin(), coins.rend());
        
        int res = INT_MAX;
        dfs(coins, amount, res, 0, 0);
        return res == INT_MAX ? -1 : res;
    }
};
*/

/*
// dfs + memo AC
class Solution {
public:
    int dfs(vector<int>& coins, int target, vector<int>& memo)
    {
        if (target < 0) return -1;
        if (memo[target] != INT_MAX) return memo[target];

        for (int i = 0; i < coins.size(); ++i) {
            int t = dfs(coins, target - coins[i], memo);
            if (t >= 0) memo[target] = min(memo[target], t + 1);
        }

        if (memo[target] == INT_MAX) memo[target] = -1;
        return memo[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;

        vector<int> memo(amount + 1, INT_MAX);
        memo[0] = 0;
        
        return dfs(coins, amount, memo);
    }
};
*/

// dp AC
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (i - coins[j] >= 0) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// @lc code=end

