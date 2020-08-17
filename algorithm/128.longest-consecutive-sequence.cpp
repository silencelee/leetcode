/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.87%)
 * Likes:    2960
 * Dislikes: 167
 * Total Accepted:    283.9K
 * Total Submissions: 639.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());

        int res = 0;
        for (auto i: nums) {
            if (hash.count(i) == 0) continue;

            int pre = i - 1;
            while (hash.count(pre) > 0) {
                hash.erase(pre);
                --pre;
            }

            int next = i + 1;
            while (hash.count(next) > 0) {
                hash.erase(next);
                ++next;
            }

            res = max(res, next - pre - 1);
        }

        return res;
    }
};
// @lc code=end

