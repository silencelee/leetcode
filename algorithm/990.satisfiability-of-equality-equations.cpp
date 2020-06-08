/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (42.60%)
 * Likes:    426
 * Dislikes: 4
 * Total Accepted:    16.8K
 * Total Submissions: 38.2K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * Given an array equations of strings that represent relationships between
 * variables, each string equations[i] has length 4 and takes one of two
 * different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not
 * necessarily different) that represent one-letter variable names.
 * 
 * Return true if and only if it is possible to assign integers to variable
 * names so as to satisfy all the given equations.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.  There is no way to assign the variables to
 * satisfy both equations.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["a==b","b==c","a==c"]
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["a==b","b!=c","c==a"]
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: ["c==c","b==d","x!=z"]
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] and equations[i][3] are lowercase letters
 * equations[i][1] is either '=' or '!'
 * equations[i][2] is '='
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class UionFind {
public:
    vector<int> fathers;

    UionFind(int n)
    {
        for (int i = 0; i < n; ++i) fathers.emplace_back(i);
    }

    int Find(int x) 
    {
        if (fathers[x] == x) return x;
        fathers[x] = Find(fathers[x]);
        return fathers[x];
    }

    void Union(int x, int y)
    {
        int fa = Find(x);
        int fb = Find(y);
        if (fa != fb) {
            fathers[fa] = fb;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UionFind uf(26);

        for (auto s : equations) {
            if (s[1] == '=') {
                uf.Union(s[0] - 'a', s[3] - 'a');
            }
        }

        for (auto s : equations) {
            if (s[1] == '!') {
                if (uf.Find(s[0] - 'a') == uf.Find(s[3] - 'a')) return false;
            }
        }

        return true;
    }
};
// @lc code=end

