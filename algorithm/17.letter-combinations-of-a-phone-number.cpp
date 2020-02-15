/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (44.64%)
 * Likes:    3112
 * Dislikes: 363
 * Total Accepted:    520.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start

/* dfs
class Solution {
public:
    const string chars[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(const string& digits, vector<string>& res, string path, int start)
    {
        int n = digits.size();
        if (start == n) {
            res.emplace_back(path);
            return;
        }

        for (auto& c : chars[digits[start] - '2']) {
            dfs(digits, res, path + c, start + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        dfs(digits, res, "", 0); 
        return res;
    }
};
*/

class Solution {
public:
    const string chars[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res(1, "");
        for (auto& d : digits) {
            vector<string> now;
            
            for (auto& c : chars[d - '2']) {
                for (auto path : res) {
                    path += c;
                    now.emplace_back(path);
                }
            }
            res = now;
        }
        
        return res;
    }
};

// @lc code=end

