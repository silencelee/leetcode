/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 *
 * https://leetcode.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (35.50%)
 * Likes:    541
 * Dislikes: 79
 * Total Accepted:    92K
 * Total Submissions: 284.5K
 * Testcase Example:  '[2,1]'
 *
 * Given an array A of integers, return true if and only if it is a valid
 * mountain array.
 * 
 * Recall that A is a mountain array if and only if:
 * 
 * 
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 * 
 * A[0] < A[1] < ... A[i-1] < A[i] 
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1]
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,5,5]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [0,3,2,1]
 * Output: true
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 * 
 * 
 * 
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
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int n = A.size();
        int i = 0;
        int j = A.size() - 1;

        while (i + 1 < n && A[i] < A[i + 1]) ++i;
        while (j > 0 && A[j - 1] > A[j]) --j;

        return (i != 0 && j != n - 1 && i == j); 
    }
};
// @lc code=end

