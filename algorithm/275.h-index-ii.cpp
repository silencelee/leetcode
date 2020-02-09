/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 *
 * https://leetcode.com/problems/h-index-ii/description/
 *
 * algorithms
 * Medium (36.03%)
 * Likes:    266
 * Dislikes: 447
 * Total Accepted:    91.5K
 * Total Submissions: 253.8K
 * Testcase Example:  '[0,1,3,5,6]'
 *
 * Given an array of citations sorted in ascending order (each citation is a
 * non-negative integer) of a researcher, write a function to compute the
 * researcher's h-index.
 * 
 * According to the definition of h-index on Wikipedia: "A scientist has index
 * h if h of his/her N papers have at least h citations each, and the other N −
 * h papers have no more than h citations each."
 * 
 * Example:
 * 
 * 
 * Input: citations = [0,1,3,5,6]
 * Output: 3 
 * Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each
 * of them had 
 * ⁠            received 0, 1, 3, 5, 6 citations respectively. 
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining 
 * two with no more than 3 citations each, her h-index is 3.
 * 
 * Note:
 * 
 * If there are several possible values for h, the maximum one is taken as the
 * h-index.
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to H-Index, where citations is now guaranteed to
 * be sorted in ascending order.
 * Could you solve it in logarithmic time complexity?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;

        int l = 0;
        int r = citations.size();

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (citations[citations.size() - mid] >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
    }
};
// @lc code=end

