/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (45.09%)
 * Likes:    1326
 * Dislikes: 57
 * Total Accepted:    248.9K
 * Total Submissions: 550.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start

// for example:
// [1, 2, 2, 2, 3, 3]
// we can choose
// 1  0, 1 time
// 2  0, 1, 2, 3 times
// 3  0, 1, 2 times

class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int pos)
    {
        if (pos == nums.size()) {
            res.emplace_back(path);
            return;
        }

        // caculate the count of the nums[pos]
        int k = 0;
        while (pos + k < nums.size() && nums[pos + k] == nums[pos]) ++k;

        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j < i; ++j) { // choose j times of nums[pos]
                path.emplace_back(nums[pos]);
            }

            dfs(nums, res, path, pos + k); // dfs next num

            for (int j = 0; j < i; ++j) {
                path.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> path;

        dfs(nums, res, path, 0);

        return res;
    }
};
// @lc code=end

