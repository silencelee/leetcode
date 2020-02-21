/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (45.35%)
 * Likes:    1327
 * Dislikes: 55
 * Total Accepted:    285K
 * Total Submissions: 626.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int cap, int pos)
    {
        if (cap == 0) {
            res.emplace_back(path);
            return;
        }

        if (cap < 0) return;

        for (int i = pos; i < candidates.size(); ++i) {
            if (i > pos && candidates[i] == candidates[i - 1]) continue;
            path.emplace_back(candidates[i]);
            dfs(candidates, res, path, cap - candidates[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> path;

        dfs(candidates, res, path, target, 0);
        return res;
    }
};
// @lc code=end

