/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.73%)
 * Likes:    6662
 * Dislikes: 793
 * Total Accepted:    889.9K
 * Total Submissions: 3.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            while ((i > 0) && (i < nums.size()) && (nums[i] == nums[i - 1])) ++i;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    do { ++l; } while ((l < r) && (nums[l] == nums[l - 1]));
                    do { --r; } while ((l < r) && (nums[r] == nums[r + 1]));
                } else if (sum < 0) {
                    do { ++l; } while ((l < r) && (nums[l] == nums[l - 1]));
                } else {
                    do { --r; } while ((l < r) && (nums[r] == nums[r + 1]));
                }
            }
        }

        return res;
    }
};
// @lc code=end

