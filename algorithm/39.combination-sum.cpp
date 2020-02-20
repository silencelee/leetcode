/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (52.98%)
 * Likes:    2973
 * Dislikes: 95
 * Total Accepted:    461.8K
 * Total Submissions: 868.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int pos, int cap)
    {
        if (cap == 0) {
            res.emplace_back(path);
            return;
        }

        if (cap < 0) return;

        for (int i = pos; i < candidates.size(); ++i) {
            path.emplace_back(candidates[i]);
            dfs(candidates, res, path, i, cap - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};

        vector<vector<int>> res;
        vector<int> path;

        dfs(candidates, res, path, 0, target);
        return res;
    }
};
// @lc code=end

