/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (52.15%)
 * Likes:    3091
 * Dislikes: 218
 * Total Accepted:    543.9K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
class Solution {
public:
    int quick_select(vector<int>& a, int l, int r, int k)
    {
        if (l >= r) return a[l];
        
        int i = l - 1;
        int j = r + 1;
        int pivot = a[l + r >> 1];
        
        while (i < j) {
            do { ++i; } while (a[i] > pivot);
            do { --j; } while (a[j] < pivot);
            if (i < j) swap(a[i], a[j]);
        }
        
        if (j - l + 1 >= k) {
            return quick_select(a, l, j, k);
        } else {
            return quick_select(a, j + 1, r, k - (j - l + 1));
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_select(nums, 0, n - 1, k);
    }
};
// @lc code=end

