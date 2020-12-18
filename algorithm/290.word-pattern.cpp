/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (36.30%)
 * Likes:    1602
 * Dislikes: 199
 * Total Accepted:    236.8K
 * Total Submissions: 620.4K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", s = "dog dog dog dog"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern contains only lower-case English letters.
 * 1 <= s.length <= 3000
 * s contains only lower-case English letters and spaces ' '.
 * s does not contain any leading or trailing spaces.
 * All the words in s are separated by a single space.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string tmp;
        while (ss >> tmp) words.emplace_back(tmp);

        int n = pattern.size();
        if (words.size() != n) return false;

        unordered_map<char, string> p2w;
        unordered_map<string, char> w2p;

        for (int i = 0; i < n; ++i) {
            char c = pattern[i];
            string w = words[i];
            if (p2w.count(c) > 0 && p2w[c] != w) return false;
            p2w[c] = w;

            if (w2p.count(w) > 0 && w2p[w] != c) return false;
            w2p[w] = c;
        }

        return true;        
    }
};
// @lc code=end

