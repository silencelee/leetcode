/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (46.04%)
 * Likes:    1062
 * Dislikes: 281
 * Total Accepted:    196.7K
 * Total Submissions: 414.2K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int t = 0;
        string res = "";
        for (int i = 0; i < num1.size() || i < num2.size(); ++i) {
            if (i < num1.size()) t += (num1[i] - '0');
            if (i < num2.size()) t += (num2[i] - '0');

            res += to_string(t % 10);
            t /= 10;
        }

        if (t > 0) res += to_string(t);
        
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

