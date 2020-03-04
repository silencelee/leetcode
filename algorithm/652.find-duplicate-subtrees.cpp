/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (48.84%)
 * Likes:    1054
 * Dislikes: 186
 * Total Accepted:    53.1K
 * Total Submissions: 108.8K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * Example 1: 
 * 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * The following are two duplicate subtrees:
 * 
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * and
 * 
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<string, int> hash;

    string dfs(TreeNode* root, vector<TreeNode*>& res)
    {
        if (root == nullptr) return "#";
        string left = dfs(root->left, res);
        string right = dfs(root->right, res);

        string tree = to_string(root->val) + "," + left + "," + right;
        ++hash[tree];
        if (hash[tree] == 2) res.emplace_back(root);
        return tree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == nullptr) return {};

        vector<TreeNode*> res;
        dfs(root, res);
        return res;     
    }
};
// @lc code=end

