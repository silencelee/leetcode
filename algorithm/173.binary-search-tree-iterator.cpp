/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (52.91%)
 * Likes:    1982
 * Dislikes: 260
 * Total Accepted:    261.1K
 * Total Submissions: 493.1K
 * Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n' +
  '[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // return 3
 * iterator.next();    // return 7
 * iterator.hasNext(); // return true
 * iterator.next();    // return 9
 * iterator.hasNext(); // return true
 * iterator.next();    // return 15
 * iterator.hasNext(); // return true
 * iterator.next();    // return 20
 * iterator.hasNext(); // return false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, there will be
 * at least a next smallest number in the BST when next() is called.
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

/* inorder travel, O(n) memory
class BSTIterator {
private:
    int cur_;
    vector<int> v_;

private:
    void inorderTravel(TreeNode* root)
    {
        if (root == nullptr) return;
        stack<TreeNode*> st;

        TreeNode* p = root;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
                st.emplace(p);
                p = p->left;
            }

            p = st.top();
            st.pop();
            v_.emplace_back(p->val);

            p = p->right;
        }
    }

public:
    BSTIterator(TreeNode* root): cur_(0) {
        inorderTravel(root);
    }
    
    // @return the next smallest number 
    int next() {
        int res = v_[cur_];
        ++cur_;
        return res;
    }
    
    // @return whether we have a next smallest number
    bool hasNext() {
        return (cur_ != v_.size());
    }
};
*/

class BSTIterator {
private:
    stack<TreeNode*> st_;

public:
    BSTIterator(TreeNode* root) 
    {
        while (root != nullptr) {
            st_.emplace(root);
            root = root->left;
        }
    }
    
    // @return the next smallest number 
    int next() {
        if (!hasNext()) return -1;

        auto p = st_.top();
        st_.pop();

        int res = p->val;
        p = p->right;
        while (p != nullptr) {
            st_.emplace(p);
            p = p->left;
        }
        return res;
    }
    
    // @return whether we have a next smallest number
    bool hasNext() {
        return !st_.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

