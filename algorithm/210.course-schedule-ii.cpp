/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (38.09%)
 * Likes:    1848
 * Dislikes: 125
 * Total Accepted:    237.8K
 * Total Submissions: 611K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    struct Graph {
        int n;
        vector<int> h;
        vector<int> e;
        vector<int> ne;
        int idx;

        vector<int> in;

        void init(int numCourses, int edge_size)
        {
            n = numCourses;
            h = vector<int>(n, -1);
            e = vector<int>(edge_size, -1);
            ne = vector<int>(edge_size, -1);
            idx = 0;

            in = vector<int>(n, 0);
        }

        void add(int x, int y)
        {
            e[idx] = y;
            ne[idx] = h[x];
            h[x] = idx++;

            ++in[y];
        }

        bool top_sort(vector<int>& res)
        {
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (in[i] == 0) q.emplace(i);
            }

            while (!q.empty()) {
                int t = q.front();
                q.pop();

                res.emplace_back(t);

                for (int i = h[t]; i != -1; i = ne[i]) {
                    int k = e[i];
                    --in[k];

                    if (in[k] == 0) q.emplace(k);
                }
            }

            return res.size() == n;            
        }
    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g;
        g.init(numCourses, prerequisites.size());

        for (auto& node : prerequisites) {
            g.add(node[1], node[0]);
        }

        vector<int> res;
        bool f = g.top_sort(res);
        if (!f) return {};
        return res;
    }
};
// @lc code=end

