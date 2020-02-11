/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (51.95%)
 * Likes:    2227
 * Dislikes: 60
 * Total Accepted:    508.4K
 * Total Submissions: 978K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* t = q.front();
                q.pop();

                level.emplace_back(t->val);

                if (t->left != nullptr) q.emplace(t->left);
                if (t->right != nullptr) q.emplace(t->right);
            }

            if (!level.empty()) res.emplace_back(level);
        }

        return res;
        
    }
};
// @lc code=end

