/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (52.42%)
 * Likes:    3437
 * Dislikes: 424
 * Total Accepted:    257.7K
 * Total Submissions: 491.6K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * 
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 1;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) >> 1;

            int cnt = 0;
            for (auto& x : nums) {
                if (x >= l && x <= mid) ++cnt;
            }

            if (cnt > (mid - l + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};
// @lc code=end

