/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.68%)
 * Likes:    5434
 * Dislikes: 464
 * Total Accepted:    793.8K
 * Total Submissions: 2.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int k = 0; k < s.size(); ++k) {
            int i = k;
            int j = k;
            while (i >= 0 && j < s.size() && s[i] == s[j]) {
                --i;
                ++j;
            }
            int len = j - i -1;
            if (ans.size() < len) {
                ans = s.substr(i + 1, len);
            }

            i = k;
            j = k + 1;
            while (i >= 0 && j < s.size() && s[i] == s[j]) {
                --i;
                ++j;
            }
            len = j - i -1;
            if (ans.size() < len) {
                ans = s.substr(i + 1, len);
            }
        }     

        return ans;
    }
};
// @lc code=end

