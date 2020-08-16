/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (43.62%)
 * Likes:    1790
 * Dislikes: 78
 * Total Accepted:    92K
 * Total Submissions: 206.8K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array which consists of non-negative integers and an integer m, you
 * can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 * 
 * 
 * Note:
 * If n is the length of array, assume the following constraints are
 * satisfied:
 * 
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 * 
 * 
 * 
 * Examples: 
 * 
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 * 
 * Output:
 * 18
 * 
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    using LL = long long;
    bool check(vector<int>& nums, int max_sum, int m)
    {
        LL total = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (total + nums[i] <= max_sum) {
                total += nums[i];
            } else {
                ++cnt;
                total = nums[i];
            }
        }

        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        LL l = 0;
        LL r = 0;

        for (int x : nums) {
            l = max(l, (LL)x);
            r += x;
        }

        while (l < r) {
            LL mid = (l + r) >> 1;

            if (check(nums, mid, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
// @lc code=end

