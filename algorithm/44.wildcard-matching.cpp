/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (25.18%)
 * Likes:    2781
 * Dislikes: 134
 * Total Accepted:    291.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*' where:
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "adceb", p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "acdcb", p = "a*c?b"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        s = " " + s;
        p = " " + p;

        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;

        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '?');
                } else if (p[j] == '*') {
                    f[i][j] = f[i][j - 1] || (i && f[i - 1][j]);
                }
            }
        }

        return f[n][m];
    }
};
// @lc code=end

