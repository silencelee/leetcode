/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.71%)
 * Likes:    2118
 * Dislikes: 1702
 * Total Accepted:    661K
 * Total Submissions: 1.9M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string res = "";
        string prefix = strs[0];
        for(int k = 0; k < prefix.size(); ++k) {
            bool f = true;
            for (int i = 1; i < strs.size(); ++i) {
                if (k >= strs[i].size() || strs[i][k] != prefix[k]) {
                    f = false;
                    break;
                }
            }

            if (!f) break;
            res += prefix[k];
        }
        return res;
    }
};
// @lc code=end
