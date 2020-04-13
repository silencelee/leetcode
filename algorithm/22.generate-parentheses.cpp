/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (59.89%)
 * Likes:    4400
 * Dislikes: 240
 * Total Accepted:    494K
 * Total Submissions: 816.6K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(int left, int right, vector<string>& res, string path)
    {
        if (left == 0 && right == 0) {
            res.emplace_back(path);
        }

        if (left > right) return;

        if (left > 0) dfs(left - 1, right, res, path + "(");
        if (right > 0) dfs(left, right - 1, res, path + ")");
    }

    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};
        vector<string> res;
        string path = "";
        dfs(n, n, res, path);
        return res;
    }
};
// @lc code=end

