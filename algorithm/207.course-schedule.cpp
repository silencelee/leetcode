/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (38.41%)
 * Likes:    1943
 * Dislikes: 92
 * Total Accepted:    233.7K
 * Total Submissions: 607.1K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
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
    bool top_sort(vector<vector<int>>& graph, vector<int>& in_degree, int numCourses, vector<int>& result)
    {
        queue<int> q;

        for (int i = 0; i < in_degree.size(); ++i) {
            if (in_degree[i] == 0) {
                q.emplace(i);
            }
        }

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            result.emplace_back(t);

            for (int i = 0; i < graph[t].size(); ++i) {
                int j = graph[t][i];
                if (--in_degree[j] == 0) {
                    q.emplace(j);
                }
            }
        }

        return result.size() == numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); ++i) {
            vector<int>& v = prerequisites[i];
            graph[v[1]].emplace_back(v[0]);
            ++in_degree[v[0]];
        }

        vector<int> result;
        bool res = top_sort(graph, in_degree, numCourses, result);
        return res;        
    }
};
// @lc code=end

