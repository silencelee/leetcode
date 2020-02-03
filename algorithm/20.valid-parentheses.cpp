/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.94%)
 * Likes:    4010
 * Dislikes: 193
 * Total Accepted:    833.2K
 * Total Submissions: 2.2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;

        std::stack<char> st;

        for (auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char t = st.top();
                if (c == ')' && t != '(') return false;
                if (c == ']' && t != '[') return false;
                if (c == '}' && t != '{') return false;
                st.pop();
            }
        }

        if (st.empty()) return true;
        return false;
    }
};
// @lc code=end
