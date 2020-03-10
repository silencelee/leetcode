/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (40.84%)
 * Likes:    2637
 * Dislikes: 158
 * Total Accepted:    227.3K
 * Total Submissions: 556.1K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) return {};

        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front() == k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.emplace_back(i);

            if (i >= k - 1) res.emplace_back(nums[dq.front()]);
        }

        return res; 
    }
};
// @lc code=end

