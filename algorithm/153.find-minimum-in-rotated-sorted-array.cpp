/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (44.14%)
 * Likes:    1562
 * Dislikes: 204
 * Total Accepted:    370.2K
 * Total Submissions: 838.8K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) >> 1;

            if (nums[mid] <= nums.back()) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return nums[l];
    }
};
// @lc code=end

