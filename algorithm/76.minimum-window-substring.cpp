/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (33.20%)
 * Likes:    3552
 * Dislikes: 253
 * Total Accepted:    335.6K
 * Total Submissions: 1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty()) return "";

        unordered_map<char, int> hash;
        for (auto& c : t) ++hash[c];

        string res;
        int count = 0;
        int min_len = INT_MAX;

        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (--hash[s[i]] >= 0) ++count;

            while (count == t.size()) {
                if (min_len > (i - left + 1)) {
                    min_len = i - left + 1;
                    res = s.substr(left, min_len);
                }

                if (++hash[s[left]] > 0) --count;
                ++left;
            }
        }

        return res; 
    }
};
// @lc code=end

