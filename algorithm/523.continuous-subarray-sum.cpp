/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (24.44%)
 * Likes:    1166
 * Dislikes: 1633
 * Total Accepted:    115K
 * Total Submissions: 470.6K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * Given a list of non-negative numbers and a target integer k, write a
 * function to check if the array has a continuous subarray of size at least 2
 * that sums up to a multiple of k, that is, sums up to n*k where n is also an
 * integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up
 * to 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5
 * and sums up to 42.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit
 * integer.
 * 
 * 
 */

// @lc code=start
/*
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        int n = nums.size();
        vector<int> sums(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                int t = sums[i] - sums[j - 1];
                if ((k != 0 && t % k == 0) || (t == 0 && k == 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        int n = nums.size();

        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (k != 0) sum %= k;
            if (hash.count(sum) > 0) {
                if (i - hash[sum] > 1) return true;
            } else {
                hash[sum] = i;
            }
        }

        return false;
    }
};
// @lc code=end

