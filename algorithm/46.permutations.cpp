/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (59.94%)
 * Likes:    3017
 * Dislikes: 92
 * Total Accepted:    509.8K
 * Total Submissions: 849K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited)
    {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int k = 0; k < nums.size(); ++k) {
            if (!visited[k]) {
                visited[k] = true;
                path.emplace_back(nums[k]);
                dfs(nums, res, path, visited);
                path.pop_back();
                visited[k] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(n, false);
        dfs(nums, res, path, visited);

        return res;
    }
};
// @lc code=end

