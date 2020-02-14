/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (65.50%)
 * Likes:    1073
 * Dislikes: 624
 * Total Accepted:    592.8K
 * Total Submissions: 904.4K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() <= 1) return;
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) swap(s[l], s[r]);
            ++l;
            --r;
        }
    }
};
// @lc code=end

