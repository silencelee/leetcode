/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.39%)
 * Likes:    2797
 * Dislikes: 385
 * Total Accepted:    381K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Notice that the solution set must not contain duplicate quadruplets.
 * 
 * 
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * Input: nums = [], target = 0
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.empty()) return res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            while (i > 0 && i < nums.size() && nums[i] == nums[i - 1]) ++i;

            for (int j = i + 1; j < nums.size(); ++j) {
                while (j > i + 1 && j < nums.size() && nums[j] == nums[j - 1]) ++j;

                int l = j + 1;
                int r = nums.size() - 1;

                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do { ++l; } while (l < r && nums[l] == nums[l - 1]);
                        do { --r; } while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum < target) {
                        do { ++l; } while (l < r && nums[l] == nums[l - 1]);
                    } else {
                        do { --r; } while (l < r && nums[r] == nums[r + 1]);
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

