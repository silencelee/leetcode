/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (31.63%)
 * Likes:    635
 * Dislikes: 1868
 * Total Accepted:    379.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

// @lc code=start

// 'A' 65 0100 0001
// 'a' 97 0110 0001
// 'A' == 'a' ^ 32  

class Solution {
public:
    bool check(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool isPalindrome(string s) {
        if (s == "") return true;

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            while (i < j && !check(s[i])) ++i;
            while (i < j && !check(s[j])) --j;

            if (s[i] != s[j] && s[i] != (s[j] ^ 32)) return false;
            ++i;
            --j;
        }

        return true;
    }
};
// @lc code=end

