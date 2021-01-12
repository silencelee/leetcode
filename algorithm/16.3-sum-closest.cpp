/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.19%)
 * Likes:    2778
 * Dislikes: 160
 * Total Accepted:    538.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;

                if (abs(sum - target) < abs(res - target)) res = sum;
                if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

