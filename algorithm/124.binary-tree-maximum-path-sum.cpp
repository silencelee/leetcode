/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (32.18%)
 * Likes:    2550
 * Dislikes: 205
 * Total Accepted:    270.1K
 * Total Submissions: 839K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
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
    int dfs(TreeNode* p, int& res)
    {
        if (p == nullptr) return 0;
        int l = max(dfs(p->left, res), 0);
        int r = max(dfs(p->right, res), 0);

        int sum = p->val + l + r;
        res = max(sum, res);
        return max(l, r) + p->val;
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
// @lc code=end

// 1 WA res must be INT_MIN, not 0
// 2 WA there is no mean if maxPathSum of left or right child < 0
// 3 WA invaild retcode of dfs, it is max(l, r) + p->val, not p->val + l + r
// 4 AC