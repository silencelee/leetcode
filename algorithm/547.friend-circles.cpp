/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (56.62%)
 * Likes:    1538
 * Dislikes: 121
 * Total Accepted:    138.2K
 * Total Submissions: 242.5K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */

// @lc code=start
class UnionFind {
private:
    vector<int> fathers;

public:
    UnionFind(int n)
    {
        for(int i = 0; i < n; ++i) fathers.emplace_back(i);
    }

    int Find(int x)
    {
        if (fathers[x] == x) return x;
        fathers[x] = Find(fathers[x]);
        return fathers[x];
    }

    void Union(int x, int y)
    {
        fathers[Find(x)] = Find(y);
    }

    int GetDisjointSetCount()
    {
        int res = 0;
        for (int i = 0; i < fathers.size(); ++i) {
            if (fathers[i] == i) ++res;
        }

        return res;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind uf(n);

        int res = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] != 1) continue;
                uf.Union(i, j);
            }
        }

        return uf.GetDisjointSetCount();
    }
};
// @lc code=end

