/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (28.42%)
 * Likes:    7561
 * Dislikes: 1190
 * Total Accepted:    718.5K
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Return the median of the two sorted arrays.
 * 
 * Follow up: The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1,length == m
 * nums2,length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) return findKthNum(nums2, j, nums1, i, k);
        if (k == 1) {
            if (i == nums1.size()) {
                return nums2[j];
            } else {
                return min(nums1[i], nums2[j]);
            }
        }

        if (i == nums1.size()) return nums2[j + k - 1];
        
        int si = min(i + k / 2, (int)nums1.size());
        int sj = j + k - k / 2;

        if (nums1[si - 1] > nums2[sj - 1]) {
            return findKthNum(nums1, i, nums2, sj, k - (sj -j));
        } else {
            return findKthNum(nums1, si, nums2, j, k - (si - i));
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        
        if (total % 2 == 0) {
            int l = findKthNum(nums1, 0, nums2, 0, total / 2);
            int r = findKthNum(nums1, 0, nums2, 0, total / 2 + 1);
            return (l + r) / 2.0f;
        } else {
            int k = total / 2 + 1;
            return findKthNum(nums1, 0, nums2, 0, k);
        }        
    }
};
// @lc code=end

