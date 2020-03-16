/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 *
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
 *
 * algorithms
 * Easy (67.01%)
 * Likes:    214
 * Dislikes: 48
 * Total Accepted:    34.7K
 * Total Submissions: 51.6K
 * Testcase Example:  '["cat","bt","hat","tree"]\n"atach"'
 *
 * You are given an array of strings words and a string chars.
 * 
 * A string is good if it can be formed by characters from chars (each
 * character can only be used once).
 * 
 * Return the sum of lengths of all good strings in words.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation: 
 * The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 =
 * 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation: 
 * The strings that can be formed are "hello" and "world" so the answer is 5 +
 * 5 = 10.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * All strings contain lowercase English letters only.
 * 
 */

// @lc code=start
class Solution {
public:
    void initHash(string chars, map<char, int>& hash)
    {
        for (char c : chars) ++hash[c];
    }
    
    int countCharacters(vector<string>& words, string chars) {
        if (words.empty()) return 0;
        
        int res = 0;
        for (string s : words) {
            map<char, int> hash;
            initHash(chars, hash);
            
            bool f = true;
            for (char c : s) {
                if (--hash[c] < 0) {
                    f = false;
                    break;
                }
            }
            
            if (f) res += s.size();
        }
        
        return res;
    }
};
// @lc code=end

