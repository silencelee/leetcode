/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (42.34%)
 * Likes:    1705
 * Dislikes: 268
 * Total Accepted:    441.9K
 * Total Submissions: 1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int t = 0;
        string res = "";
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
            if (i >= 0) t += a[i] - '0';
            if (j >= 0) t += b[j] - '0';

            res += to_string(t % 2);
            t /= 2;
        }

        if (t > 0) res += to_string(t);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

