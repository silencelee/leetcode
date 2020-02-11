/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (60.55%)
 * Likes:    2431
 * Dislikes: 100
 * Total Accepted:    617.7K
 * Total Submissions: 1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

/* recursive
class Solution {
public:
    void dfs(TreeNode* p, vector<int>& res)
    {
        if (p == nullptr) return;
        dfs(p->left, res);
        res.emplace_back(p->val);
        dfs(p->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);

        return res;
    }
};
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;

        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.emplace(p);
                p = p->left;
            }

            p = st.top();
            st.pop();
            res.emplace_back(p->val);

            p = p->right;
        }

        return res;
    }
};

// @lc code=end

