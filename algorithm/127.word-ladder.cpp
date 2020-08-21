/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (27.65%)
 * Likes:    3364
 * Dislikes: 1209
 * Total Accepted:    443.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        if (hash.count(endWord) == 0) return 0;

        unordered_map<string, int> dist;
        dist[beginWord] = 1;

        queue<string> q;
        q.emplace(beginWord);

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            string origin = t;
            for (int i = 0; i < t.size(); ++i) {
                t = origin;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (t[i] == c) continue;

                    t[i] = c;
                    if (hash.count(t) > 0 && dist.count(t) == 0) {
                        dist[t] = dist[origin] + 1;
                        if (t == endWord) return dist[t];
                        q.emplace(t);
                    }
                }
            }
        }

        return 0;
    }
};
// @lc code=end

