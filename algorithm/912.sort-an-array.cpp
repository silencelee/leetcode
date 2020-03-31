/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (62.70%)
 * Likes:    302
 * Dislikes: 211
 * Total Accepted:    57.3K
 * Total Submissions: 91.5K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;

        int i = l - 1;
        int j = r + 1;
        int pivot = nums[l + r >> 1];

        while (i < j) {
            do { ++i; } while (nums[i] < pivot);
            do { --j; } while (nums[j] > pivot);
            if (i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }

    void merge_sort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int pivot_index = l + r >> 1;
        merge_sort(nums, l, pivot_index);
        merge_sort(nums, pivot_index + 1, r);

        vector<int> tmp;
        int i = l;
        int j = pivot_index + 1;

        while (i <= pivot_index && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp.emplace_back(nums[i]);
                ++i;
            } else {
                tmp.emplace_back(nums[j]);
                ++j;
            }
        }

        while (i <= pivot_index) tmp.emplace_back(nums[i++]);
        while (j <= r) tmp.emplace_back(nums[j++]);
        
        for (int i = l, k = 0; i <= r; ++i) nums[i] = tmp[k++];
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;

        quick_sort(nums, 0, nums.size() - 1);
        //merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

