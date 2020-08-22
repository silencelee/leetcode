/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.30%)
 * Likes:    2352
 * Dislikes: 103
 * Total Accepted:    397.2K
 * Total Submissions: 821.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.emplace(root);

        bool leftToRight = true;
        while (!q.empty()) {
            int n = q.size();

            vector<int> level;
            for (int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                
                if (leftToRight) {
                    level.emplace_back(t->val);
                } else {
                    level.insert(level.begin(), t->val);
                }

                if (t->left != nullptr) q.emplace(t->left);
                if (t->right != nullptr) q.emplace(t->right);
            }

            res.emplace_back(level);
            leftToRight = !leftToRight;
        }

        return res;
    }
};
// @lc code=end

