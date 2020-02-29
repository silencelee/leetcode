/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 *
 * https://leetcode.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (36.82%)
 * Likes:    449
 * Dislikes: 47
 * Total Accepted:    31.3K
 * Total Submissions: 84.9K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * Remember the story of Little Match Girl? By now, you know exactly what
 * matchsticks the little match girl has, please find out a way you can make
 * one square by using up all those matchsticks. You should not break any
 * stick, but you can link them up, and each matchstick must be used exactly
 * one time.
 * 
 * ⁠Your input will be several matchsticks the girl has, represented with their
 * stick length. Your output will either be true or false, to represent whether
 * you could make one square using all the matchsticks the little match girl
 * has.
 * 
 * Example 1:
 * 
 * Input: [1,1,2,2,2]
 * Output: true
 * 
 * Explanation: You can form a square with length 2, one side of the square
 * came two sticks with length 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,3,3,4]
 * Output: false
 * 
 * Explanation: You cannot find a way to form a square with all the
 * matchsticks.
 * 
 * 
 * 
 * Note:
 * 
 * The length sum of the given matchsticks is in the range of 0 to 10^9.
 * The length of the given matchstick array will not exceed 15.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<int>& nums, int cur, int pos, vector<bool>& used, int cur_len, int target_len)
    {
        if (cur == 4) return true;
        if (cur_len == target_len) return dfs(nums, cur + 1, 0, used, 0, target_len);

        for (int i = pos; i < nums.size(); ++i) {
            if (!used[i]) {
                if (cur_len + nums[i] > target_len) continue;
                used[i] = true;
                if (dfs(nums, cur, i + 1, used, cur_len + nums[i], target_len)) return true;
                used[i] = false;

                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& nums) {
        if (nums.empty()) return false;

        int total = 0;
        for (int n : nums) total += n;
        if (total % 4 != 0) return false;
        
        sort(nums.rbegin(), nums.rend());

        int n = nums.size();
        int len = total / 4;
        vector<bool> used(n, false);
        return dfs(nums, 0, 0, used, 0, len);
    }
};
// @lc code=end

