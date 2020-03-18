/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    2807
 * Dislikes: 970
 * Total Accepted:    326.4K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i - 1] < nums[i]) {
                int j = nums.size() - 1;
                while (nums[j] <= nums[i - 1] && j >= i) --j;
                
                swap(nums[j], nums[i - 1]);
                reverse(nums.begin() + i, nums.end()); 
                return;
            }
        }

        reverse(nums.begin(), nums.end());   
    }
};
// @lc code=end
