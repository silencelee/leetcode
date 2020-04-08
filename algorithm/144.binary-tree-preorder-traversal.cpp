/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (54.02%)
 * Likes:    1255
 * Dislikes: 53
 * Total Accepted:    451K
 * Total Submissions: 830.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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

/*
class Solution {
public:
    void doPreorderTraversal(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;
        res.emplace_back(root->val);
        doPreorderTraversal(root->left, res);
        doPreorderTraversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        doPreorderTraversal(root, res);
        return res;
    }
};
*/

/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        stack<TreeNode*> st;
        st.emplace(root);

        while (!st.empty()) {
            TreeNode* p = st.top();
            st.pop();

            res.emplace_back(p->val);

            if (p->right != nullptr) st.emplace(p->right);
            if (p->left != nullptr) st.emplace(p->left);    
        }

        return res;
    }
};
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;

        while (!st.empty() || p != nullptr) {
            if (p != nullptr) {
                res.emplace_back(p->val);
                st.emplace(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }

        return res;
    }
};

// @lc code=end

