/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (43.99%)
 * Likes:    1536
 * Dislikes: 56
 * Total Accepted:    308.7K
 * Total Submissions: 700.6K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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

        for (int i = 0; i < nums.size(); ++i) {
            
            if (!visited[i]) {
                visited[i] = true;
                path.emplace_back(nums[i]);

                dfs(nums, res, path, visited);

                path.pop_back();
                visited[i] = false;

                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> res;
        vector<int> path;

        dfs(nums, res, path, visited);
        return res;
    }
};
// @lc code=end

