/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.02%)
 * Likes:    13266
 * Dislikes: 481
 * Total Accepted:    2.5M
 * Total Submissions: 5.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                result.emplace_back(i);
                result.emplace_back(it->second);

                return result;
            } else {
                m[nums[i]] = i;
            }
        }

        return result;
    }
};
// @lc code=end

