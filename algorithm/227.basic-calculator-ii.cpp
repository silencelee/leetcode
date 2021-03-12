/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (38.10%)
 * Likes:    2200
 * Dislikes: 344
 * Total Accepted:    255.1K
 * Total Submissions: 660.8K
 * Testcase Example:  '"3+2*2"'
 *
 * Given a string s which represents an expression, evaluate this expression
 * and return its value. 
 * 
 * The integer division should truncate toward zero.
 * 
 * 
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of integers and operators ('+', '-', '*', '/') separated by some
 * number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range
 * [0, 2^31 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void eval(stack<int>& nums, stack<char>& ops)
    {
        int b = nums.top();
        nums.pop();

        int a = nums.top();
        nums.pop();

        char op = ops.top();
        ops.pop();

        int res = 0;
        if (op == '+') {
            res = a + b;
        } else if (op == '-') {
            res = a - b;
        } else if (op == '*') {
            res = a * b;
        } else {
            res = a / b;
        }

        nums.emplace(res);
    }

    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;

        unordered_map<char, int> pr;
        pr['+'] = 1;
        pr['-'] = 1;
        pr['*'] = 2;
        pr['/'] = 2;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == ' ') continue;

            if (isdigit(c)) {
                int t = 0;
                int j = i;
                while (j < s.size() && isdigit(s[j])) t = t * 10 + (s[j++] - '0');
                nums.emplace(t);

                i = j - 1;
            } else if (c == '(') {
                ops.emplace(c);
            } else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') eval(nums, ops);
                ops.pop();
            } else {
                while (!ops.empty() && ops.top() != '(' && pr[ops.top()] >= pr[c]) eval(nums, ops);
                ops.emplace(c);
            }
        }

        while (!ops.empty()) eval(nums, ops);

        return nums.top();
    }
};
// @lc code=end

