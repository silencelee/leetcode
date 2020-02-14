/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.51%)
 * Likes:    7727
 * Dislikes: 457
 * Total Accepted:    1.3M
 * Total Submissions: 4.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start

// brute force 
// TLE
/*
class Solution {
public:
    int checkUnique(string s)
    {
        unordered_set<char> hash;
        for (int i = 0; i < s.size(); ++i) {
            if (hash.find(s[i]) != hash.end()) {
                return i;
            }
            hash.emplace(s[i]);
        }

        return s.size();
    }
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j){
                string sub = s.substr(i, j - i + 1);
                res = max(res, checkUnique(sub));
            }
        }

        return res;
    }
};
*/

/* sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int res = 0;
        unordered_set<char> hash;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (j < s.size()) {
                if (hash.find(s[j]) == hash.end()) {
                    hash.emplace(s[j]);
                    ++j;
                } else {
                    hash.erase(s[i]);
                    break;
                }
            }
            res = max(res, j - i);
        }
        return res;
    }
};
*/

// sliding window optimized
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int res = 0;
        unordered_map<char, int> hash;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (hash.find(s[j]) != hash.end()) {
                i = max(i, hash[s[j]] + 1);
            }
            
            res = max(res, j - i + 1);
            hash[s[j]] = j; 
        }
        return res;
    }
};

// @lc code=end

