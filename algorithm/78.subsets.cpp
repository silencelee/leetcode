/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (57.60%)
 * Likes:    2878
 * Dislikes: 68
 * Total Accepted:    481.2K
 * Total Submissions: 833.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start

/* dfs
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int pos)
    {
        if (pos == nums.size()) {
            res.emplace_back(path);
            return;
        }

        // not select 
        dfs(nums, res, path, pos + 1);

        // select the num in pos
        path.emplace_back(nums[pos]);
        dfs(nums, res, path, pos + 1);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<vector<int>> res;
        vector<int> path;

        dfs(nums, res, path, 0);
        return res;
    }
};
*/

/*
                        []        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []
*/
// level 0 [empty set]
// new level  =  [pre level set] + [pre level set + cur num]
// the answer if the leaves of the tree  

/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<vector<int>> res(1);

        for (int i = 0; i < nums.size(); ++i) {
            int size = res.size();

            for (int j = 0; j < size; ++j) {
                res.emplace_back(res[j]);
                res.back().emplace_back(nums[i]);
            }
        }
        return res;
    }
};
*/

// bit
// example: [1, 2 ,3]
// 000 {}
// 001 {1}
// 010 {2}
// 011 {1,2}
// 100 {3}
// 101 {1,3}
// 110 {2,3}
// 111 {1,2,3}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<vector<int>> res;

        unsigned long long len = 1 << nums.size();

        for (int i = 0; i < len; ++i) {
            vector<int> path;
            for (int j = 0; j < nums.size(); ++j) {
                if (i >> j & 1) {
                    path.emplace_back(nums[j]);
                }
            }

            res.emplace_back(path);
        }
        return res;
    }
};
// @lc code=end

