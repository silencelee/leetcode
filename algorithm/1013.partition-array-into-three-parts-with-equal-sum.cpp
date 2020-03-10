/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 *
 * https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/
 *
 * algorithms
 * Easy (57.02%)
 * Likes:    287
 * Dislikes: 47
 * Total Accepted:    26.6K
 * Total Submissions: 46.5K
 * Testcase Example:  '[0,2,1,-6,6,-7,9,1,2,0,1]'
 *
 * Given an array A of integers, return true if and only if we can partition
 * the array into three non-empty parts with equal sums.
 * 
 * Formally, we can partition the array if we can find indexes i+1 < j with
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1]
 * + ... + A[A.length - 1])
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
 * Output: true
 * Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [3,3,6,5,-2,2,5,1,-9,4]
 * Output: true
 * Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= A.length <= 50000
 * -10^4 <= A[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        if (n < 3) return false;
        
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += A[i];
        
        if (sum % 3 != 0) return false;
        int target = sum / 3;
        
        int i = 0;
        int cur = 0;
        while (i < n) {
            cur += A[i];
            if (cur == target) break;
            ++i;
        }
        
        if (cur != target) return false;
        int j = i + 1;
        while (j < n - 1) { // left 1 elment at least
            cur += A[j];
            if (cur == target * 2) return true;
            ++j;
        }
        
        return false;
    }
};
// @lc code=end

