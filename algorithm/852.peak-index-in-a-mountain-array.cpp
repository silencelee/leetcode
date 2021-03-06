/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 *
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (70.76%)
 * Likes:    447
 * Dislikes: 941
 * Total Accepted:    123.3K
 * Total Submissions: 174.2K
 * Testcase Example:  '[0,1,0]'
 *
 * Let's call an array A a mountain if the following properties hold:
 * 
 * 
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] <
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * Given an array that is definitely a mountain, return any i such that A[0] <
 * A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 * 
 * 
 * Input: [0,1,0]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,2,1,0]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A is a mountain, as defined above.
 * 
 * 
 */

// @lc code=start

/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int n = A.size();
        for (int i = 1; i < n - 1; ++i) {
            if (A[i] > A[i + 1])
                return i;
        }

        return -1;
    }
};
*/

// bsearch
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        int l = 0;
        int r = A.size() - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (A[mid] > A[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

// @lc code=end
