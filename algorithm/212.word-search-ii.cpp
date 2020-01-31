/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (31.73%)
 * Likes:    1745
 * Dislikes: 89
 * Total Accepted:    159.1K
 * Total Submissions: 500.8K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */

// @lc code=start

class Trie
{
private:
    struct TrieNode
    {
        TrieNode* child[26];
        bool isWord;

        TrieNode(): isWord(false)
        {
            for (auto &c: child) {
                c = nullptr;
            }
        }
    };

    TrieNode* root_;

public:
    Trie()
    {
        root_ = new TrieNode();
    }

    void Insert(string word)
    {
        TrieNode* p = root_;
        for (auto& c : word) {
            if (p->child[c - 'a'] == nullptr) {
                p->child[c - 'a'] = new TrieNode();
            }

            p = p->child[c - 'a'];
        }

        p->isWord = true;
    }

    bool StartWith(string prefix)
    {
        TrieNode* p = root_;
        for (auto& c : prefix) {
            if (p->child[c - 'a'] == nullptr) return false;
            p = p->child[c - 'a'];
        }

        return true;
    }

    bool Search(string word)
    {
        TrieNode* p = root_;
        for (auto& c : word) {
            if (p->child[c - 'a'] == nullptr) return false;
            p = p->child[c - 'a'];
        }

        return p->isWord;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, std::unordered_set<string>& res, string cur, int x, int y, vector<vector<bool>>& visited, Trie* t)
    {
        int m = board.size();
        int n = board[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y]) return;
        cur += board[x][y];

        if (!t->StartWith(cur)) return;
        if (t->Search(cur)) res.emplace(cur);

        visited[x][y] = true;

        dfs(board, res, cur, x - 1, y, visited, t); // up
        dfs(board, res, cur, x + 1, y, visited, t); // down
        dfs(board, res, cur, x, y - 1, visited, t); // left
        dfs(board, res, cur, x, y + 1, visited, t); // right

        visited[x][y] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        std::unordered_set<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return vector<string>();

        Trie t;
        for (auto &s : words) t.Insert(s);

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, res, "", i, j, visited, &t);      
            }
        }
        return vector(res.begin(), res.end());        
    }
};
// @lc code=end
// 1 WA need a set at first, otherwise, the result may contain duplicated string
// 2 AC

