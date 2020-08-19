/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (59.25%)
 * Likes:    2837
 * Dislikes: 116
 * Total Accepted:    196.3K
 * Total Submissions: 323.3K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if (s == "") return 0;

        int res = 0;
        for (int k = 0; k < s.size(); ++k) {
            int i = k;
            int j = k;

            while (i >= 0 && j < s.size() && s[i] == s[j]) {
                ++res;
                --i;
                ++j;
            }

            i = k;
            j = k + 1;
            
            while (i >= 0 && j < s.size() && s[i] == s[j]) {
                ++res;
                --i;
                ++j;
            }
        }

        return res;
    }
};
// @lc code=end

