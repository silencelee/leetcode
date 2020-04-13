/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (44.70%)
 * Likes:    2528
 * Dislikes: 192
 * Total Accepted:    414.8K
 * Total Submissions: 927.7K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */

// @lc code=start
/*
class Solution {
public:
    int partition(vector<int>& nums, int l, int r, int pivot)
    {
        int pos = l - 1;
        for (int i = l; i <= r; ++i) {
            if (nums[i] == pivot) swap(nums[++pos], nums[i]);
        }
        return ++pos;
    }

    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int index = partition(nums, 0, nums.size() - 1, 0);
        partition(nums, index, nums.size() - 1, 1);
    }
};
*/

/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int pos_0 = -1;
        int pos_2 = nums.size();

        for (int i = 0; i < pos_2; ++i) {
            if (nums[i] == 0) swap(nums[++pos_0], nums[i]);
            if (nums[i] == 2) {
                swap(nums[--pos_2], nums[i]);
                --i;
            }
        }
    }
};
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int pos_0 = -1;
        int pos_2 = nums.size();

        for (int i = 0; i < pos_2; ++i) {
            while (nums[i] == 2 && i < pos_2) swap(nums[--pos_2], nums[i]);
            if (nums[i] == 0) swap(nums[++pos_0], nums[i]);
        }
    }
};
// @lc code=end

