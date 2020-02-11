/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (45.42%)
 * Likes:    2541
 * Dislikes: 74
 * Total Accepted:    297.9K
 * Total Submissions: 655.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    unordered_map<int, int> hash;

    TreeNode* buildTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir)
    {
        if (pl > pr) return nullptr;

        int rootVal = preorder[pl];
        TreeNode* root = new TreeNode(rootVal);

        int index = hash[rootVal];
        int len = index - il;
        root->left = buildTree(preorder, pl + 1, pl + len, inorder, il, index - 1);
        root->right = buildTree(preorder, pl + len + 1, pr, inorder, index + 1, ir);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        for (int i = 0; i < inorder.size(); ++i) hash[inorder[i]] = i;
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        
    }
};
// @lc code=end

