/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.24%)
 * Likes:    2795
 * Dislikes: 120
 * Total Accepted:    249.9K
 * Total Submissions: 914.6K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start

/*
// consider that
// '(' = 1
// ')' = -1
// the prefix sum of valid parentheses substring should >= 0
// the sum of valid parentheses substring should == 0
// it is must be invalid if the sum of parentheses substring < 0

class Solution {
public:
    int solve(string s)
    {
        int res = 0;
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++cnt;
            } else {
                --cnt;
            }

            if (cnt == 0) {
                res = max(res, i - j + 1);
            } else if (cnt < 0) {
                j = i + 1;
                cnt = 0;
            }
        }

        return res;
    }
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;

        int res = solve(s);
        // convert '(' to ')', and convert ')' to '('
        for (auto& c : s) c ^= 1;
        // eg: convert "(()" to "())"
        reverse(s.begin(), s.end());
        res = max(res, solve(s));        

        return res;
    }
};
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;

        int res = 0;
        stack<int> st({-1});
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.emplace(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.emplace(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }

        return res;
    }
};

// @lc code=end

