/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (37.71%)
 * Likes:    610
 * Dislikes: 235
 * Total Accepted:    148K
 * Total Submissions: 391.4K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};

        unordered_map<string, int> hash;
        vector<string> res;
        for (int i = 0;  i + 10 <= s.size(); ++i) {
            string str = s.substr(i, 10);
            ++hash[str];
            if (hash[str] == 2) res.emplace_back(str);
        }

        return res;
    }
};
// @lc code=end

