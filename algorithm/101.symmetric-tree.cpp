/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.51%)
 * Likes:    3221
 * Dislikes: 75
 * Total Accepted:    543.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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

/* recursively
class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr || right == nullptr)
            return (left == nullptr && right == nullptr);

        if (left->val != right->val)
            return false;

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        return isSymmetric(root->left, root->right);
    }
};
*/

// inorder travel
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        stack<TreeNode*> st_left;
        stack<TreeNode*> st_right;

        auto p = root->left;
        auto q = root->right;

        while (!st_left.empty() || p != nullptr || !st_right.empty() || q != nullptr) {
            while (p != nullptr && q != nullptr) {
                st_left.emplace(p);
                p = p->left;

                st_right.emplace(q);
                q = q->right;
            }

            if (p != nullptr || q != nullptr) return false;

            p = st_left.top();
            st_left.pop();

            q = st_right.top();
            st_right.pop();

            if (p->val != q->val) return false;
            p = p->right;
            q = q->left;
        }

        return true;
    }
};
// @lc code=end
