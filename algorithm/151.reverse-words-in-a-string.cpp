/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (19.18%)
 * Likes:    807
 * Dislikes: 2616
 * Total Accepted:    350.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

// @lc code=start

/* use stringstream
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string res = "";
        string tmp = "";

        while (ss >> tmp) {
            if (res == "") {
                res = tmp;
            } else {
                res = tmp + " " + res;
            }
            
        }

        return res;
    }
};
*/

class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (i < s.size() && s[i] == ' ') ++i;
            if (i == s.size()) break;

            int j = i;
            while (j < s.size() && s[j] != ' ') ++j;

            reverse(s.begin() + i, s.begin() + j);

            if (k != 0) s[k++] = ' ';
            while (i < j) s[k++] = s[i++];
        }

        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

