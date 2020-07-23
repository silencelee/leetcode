/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.76%)
 * Likes:    1280
 * Dislikes: 504
 * Total Accepted:    195.5K
 * Total Submissions: 552.1K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * A valid IP address consists of exactly four integers (each integer is
 * between 0 and 255) separated by single points.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(string s, vector<string>& res, vector<int>& path, int pos, int cnt)
    {
        if (pos == s.size()) {
            if (cnt == 4) {
                string ip = to_string(path[0]);
                for (int i = 1; i < 4; ++i) {
                    ip += "." + to_string(path[i]);
                }
                res.emplace_back(ip);
            }
            return;
        }

        if (cnt > 4) return;

        if (s[pos] == '0') {
            path.emplace_back(0);
            dfs(s, res, path, pos + 1, cnt + 1);
            path.pop_back();
        } else {
            int t = 0;
            for (int i = pos; i < s.size(); ++i) {
                t = t * 10 + (s[i] - '0');
                if (t > 255) break;

                path.emplace_back(t);
                dfs(s, res, path, i + 1, cnt + 1);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.empty()) return res;

        vector<int> path;
        dfs(s, res, path, 0, 0);
        return res;
    }
};
// @lc code=end

