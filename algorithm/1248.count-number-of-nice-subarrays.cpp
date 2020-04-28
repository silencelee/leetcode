/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (54.28%)
 * Likes:    284
 * Dislikes: 8
 * Total Accepted:    11.4K
 * Total Submissions: 20.7K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Given an array of integers nums and an integer k. A subarray is called nice
 * if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd_prefix_sum;
        odd_prefix_sum.emplace_back(0);

        for (int x : nums) odd_prefix_sum.emplace_back(odd_prefix_sum.back() + (x & 1));

        unordered_map<int, int> hash;
        hash[0] = 1;

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            res += hash[odd_prefix_sum[i] - k];
            ++hash[odd_prefix_sum[i]];
        }

        return res;
    }
};
// @lc code=end

