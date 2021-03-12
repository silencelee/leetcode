/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (37.84%)
 * Likes:    2061
 * Dislikes: 164
 * Total Accepted:    199.4K
 * Total Submissions: 522.1K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing an expression, implement a basic calculator to
 * evaluate it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void eval(stack<int>& nums, stack<char>& op)
    {
        int b = nums.top();
        nums.pop();

        int a = nums.top();
        nums.pop();

        char oper = op.top();
        op.pop();

        int res = 0;
        if (oper == '+') {
            res = a + b;
        } else {
            res = a - b;
        }

        nums.emplace(res);
    }

    int calculate(string s) {
        string str = "0";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;

            if (s[i] == '-') {
                if (str.back() == '-') {
                    str.pop_back();
                    str += '+';
                    continue;
                }
                
                if (str.back() == '+' || str.back() == '(') {
                    str += '0';
                }
            }

            str += s[i];
        }

        s = str;
        //cout << "s="<<s << endl;

        stack<int> nums;
        stack<char> op;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == ' ') continue;

            if (isdigit(c)) {
                int t = 0;
                int j = i;
                while (isdigit(s[j]) && j < s.size()) t = t * 10 + (s[j++] - '0');

                nums.emplace(t);
                i = j - 1;
            } else if (c == '(') {
                op.emplace(c);
            } else if (c == ')') {
                while (!op.empty() && op.top() != '(') eval(nums, op);
                op.pop();
            } else {
                while (!op.empty() && op.top() != '(') eval(nums, op);
                op.emplace(c);
            }
        }

        while (!op.empty()) eval(nums, op);

        return nums.top();
    }
};
// @lc code=end

