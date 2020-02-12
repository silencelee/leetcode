/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (44.88%)
 * Likes:    2376
 * Dislikes: 118
 * Total Accepted:    264.9K
 * Total Submissions: 589.5K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        stringstream ss;
        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* p = q.front();
                q.pop();

                if (p != nullptr) {
                    ss << to_string(p->val) << " ";
                    q.emplace(p->left); // whether or not p->left == nullptr
                    q.emplace(p->right); // whether or not p->right == nullptr
                } else {
                    ss << "null" << " ";
                }
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val = "";
        ss >> val;

        TreeNode* root = new TreeNode(stoi(val));
        TreeNode* p = root;

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (!(ss >> val)) break;

            if (val != "null") {
                TreeNode* p = new TreeNode(stoi(val));
                cur->left = p;
                q.emplace(cur->left);
            }

            if (!(ss >> val)) break;

            if (val != "null") {
                TreeNode* p = new TreeNode(stoi(val));
                cur->right = p;
                q.emplace(cur->right);
            }
        }

        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

// 1 WA without checking root == nullptr
// 2 AC
