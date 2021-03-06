/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (37.97%)
 * Likes:    1674
 * Dislikes: 3569
 * Total Accepted:    491.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.empty() || nums2.empty()) return;

        int index = m + n - 1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 && j >=0) {
            if (nums1[i] <= nums2[j]) {
                nums1[index] = nums2[j];
                --j;
            } else {
                nums1[index] = nums1[i];
                --i;
            }

            --index;
        }

        while (j >= 0 && index >= 0) {
            nums1[index--] = nums2[j--];
        }
    }
};
// @lc code=end

