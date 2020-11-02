/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (59.56%)
 * Likes:    1050
 * Dislikes: 1345
 * Total Accepted:    410K
 * Total Submissions: 644.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) return res;

        unordered_set<int> s;
        for (auto x : nums1) s.insert(x);

        for (auto x : nums2) {
            if (s.count(x) > 0) {
                res.emplace_back(x);
                s.erase(x);
            }
        }

        return res;
    }
};
// @lc code=end

