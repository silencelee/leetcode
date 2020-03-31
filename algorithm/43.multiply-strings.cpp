/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.69%)
 * Likes:    1510
 * Dislikes: 698
 * Total Accepted:    265.7K
 * Total Submissions: 808.7K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> product(num1.size() + num2.size(), 0);
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                product[num1.size() - i + num2.size() - j - 2] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int t = 0;
        for (int i = 0; i < product.size(); ++i) {
            int& x = product[i];
            t += x;
            x = t % 10;
            t = t / 10;
        }
        
        while (product.size() > 1 && product.back() == 0) product.pop_back();
        string res = "";
        for (int i = product.size() - 1; i >= 0; --i) res += to_string(product[i]);
        return res;
    }
};
// @lc code=end
