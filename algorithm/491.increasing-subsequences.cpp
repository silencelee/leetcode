/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (43.97%)
 * Likes:    756
 * Dislikes: 116
 * Total Accepted:    48.8K
 * Total Submissions: 105.5K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int pos)
    {
        if (path.size() >= 2) {
            res.emplace_back(path);
        }

        if (pos == nums.size()) {
            return;
        }
        
        unordered_set<int> hash;
        for (int i = pos; i < nums.size(); ++i) {
            if ((path.empty() || nums[i] >= path.back()) && hash.count(nums[i]) == 0) {
                path.emplace_back(nums[i]);
                dfs(nums, res, path, i + 1);
                path.pop_back();
                hash.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;

        vector<int> path;
        dfs(nums, res, path, 0);
        return res;
    }
};
// @lc code=end

