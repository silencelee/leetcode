/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (40.79%)
 * Likes:    909
 * Dislikes: 57
 * Total Accepted:    78.4K
 * Total Submissions: 191.3K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 * 
 * 
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * 
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 * 
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * 
 * 
 * Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: "1,#"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "9,#,#,1"
 * Output: false
 */

// @lc code=start
class Solution {
public:
    bool dfs(string s, int& u)
    {
        if (u == s.size()) return false;

        if (s[u] == '#') {
            u += 2; // skp "#,"
            return true;
        }

        while (s[u] != ',') ++u;
        ++u; //skip ','

        return dfs(s, u) && dfs(s, u);
    }

    bool isValidSerialization(string preorder) {
        if (preorder == "") return true;
        preorder += ",";
        
        int u = 0;
        if (!dfs(preorder, u)) return false;
        return u == preorder.size();
    }
};
// @lc code=end

