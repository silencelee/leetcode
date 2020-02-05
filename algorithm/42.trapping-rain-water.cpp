/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (46.47%)
 * Likes:    5448
 * Dislikes: 104
 * Total Accepted:    419.5K
 * Total Submissions: 901.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start

/* brute-force
1 RTE (--unsign int) int loop
2 AC
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int res = 0;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            int max_left = 0;
            for (int j = i; j >= 0; --j) {
                if (height[j] > max_left) max_left = height[j];
            }

            int max_right = 0;
            for (int j = i; j < n; ++j) {
                if (height[j] > max_right) max_right = height[j];
            }

            res += min(max_left, max_right) - height[i];
        }

        return res;
    }
};
*/

/* Dynamic Programming
class Solution {
public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;

        int res = 0;
        int n = height.size();
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);

        max_left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }

        max_right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }

        for (int i = 0; i < n; ++i) {
            res += min(max_left[i], max_right[i]) - height[i];
        }

        return res;
    }
};
*/

/* tow pointer
class Solution {
public:
    int trap(vector<int>& height) 
    {
        if (height.empty()) return 0;

        int res = 0;
        int l = 0;
        int r = height.size() - 1;

        int max_left = 0;
        int max_right = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] > max_left) max_left = height[l];
                res += max_left - height[l];
                ++l;
            } else {
                if (height[r] > max_right) max_right = height[r];
                res += max_right - height[r];
                --r;
            }
        }

        return res;

    }
};
*/

class Solution {
public:
    int trap(vector<int>& height)
    {
        if (height.empty())
            return 0;

        int res = 0;
        std::stack<int> st;

        int i = 0;
        while (i < height.size()) {
            if (st.empty() || height[i] < height[st.top()]) {
                st.emplace(i);
                ++i;
            } else {
                int t = st.top();
                st.pop();
                if (st.empty())
                    continue;

                int h = min(height[i], height[st.top()]) - height[t];
                int len = i - st.top() - 1;
                res += h * len;
            }
        }


        return res;

    }
};

// @lc code=end
