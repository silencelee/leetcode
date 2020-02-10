/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (52.33%)
 * Likes:    2522
 * Dislikes: 146
 * Total Accepted:    482.2K
 * Total Submissions: 921.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for (auto& s : strs) {
            auto key = s;
            sort(key.begin(), key.end());
            hash[key].emplace_back(s);
        }

        vector<vector<string>> res;
        for(auto& entry : hash) {
            res.emplace_back(entry.second);
        }

        return res;
    }
};
// @lc code=end

