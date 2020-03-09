/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 *
 * https://leetcode.com/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (33.96%)
 * Likes:    507
 * Dislikes: 26
 * Total Accepted:    17K
 * Total Submissions: 50.1K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * Given a circular array C of integers represented by A, find the maximum
 * possible sum of a non-empty subarray of C.
 * 
 * Here, a circular array means the end of the array connects to the beginning
 * of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and
 * C[i+A.length] = C[i] when i >= 0.)
 * 
 * Also, a subarray may only include each element of the fixed buffer A at most
 * once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not
 * exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,-2,3,-2]
 * Output: 3
 * Explanation: Subarray [3] has maximum sum 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,-3,5]
 * Output: 10
 * Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [3,-1,2,-1]
 * Output: 4
 * Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [3,-2,2,-3]
 * Output: 3
 * Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [-2,-3,-1]
 * Output: -1
 * Explanation: Subarray [-1] has maximum sum -1
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * -30000 <= A[i] <= 30000
 * 1 <= A.length <= 30000
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) A.emplace_back(A[i]);

        vector<int> sum(n * 2 + 1, 0);
        for (int i = 1; i <= 2 * n; ++i) sum[i] = sum[i - 1] + A[i - 1];

        int res = INT_MIN;
        deque<int> dq;
        dq.emplace_back(0);

        for (int i = 1; i <= 2 * n; ++i) {
            if (!dq.empty() && i - dq.front() > n) dq.pop_front();
            res = max(res, sum[i] - sum[dq.front()]);
            while (!dq.empty() && sum[dq.back()] > sum[i]) dq.pop_back();
            dq.emplace_back(i);
        }
        return res;
    }
};
// @lc code=end

