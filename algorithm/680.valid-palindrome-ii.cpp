/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (35.80%)
 * Likes:    1437
 * Dislikes: 94
 * Total Accepted:    151.5K
 * Total Submissions: 418.3K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int l , int r)
    {
        int i = l;
        int j = r;

        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                break;
            }
        }

        if (i >= j) return true;
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1); 
    }
};
// @lc code=end

