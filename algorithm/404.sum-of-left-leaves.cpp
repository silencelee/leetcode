/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (50.23%)
 * Likes:    1433
 * Dislikes: 142
 * Total Accepted:    213.1K
 * Total Submissions: 409.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int res = 0;
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            if (t->left != nullptr) {
                if (isLeaf(t->left)) {
                    res += t->left->val;
                } else {
                    q.emplace(t->left);
                }
            }

            if (t->right != nullptr) {
                if (!isLeaf(t->right)) {
                    q.emplace(t->right);
                }
            }
        }

        return res;
    }
};
// @lc code=end

