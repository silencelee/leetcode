/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (52.62%)
 * Likes:    1174
 * Dislikes: 140
 * Total Accepted:    138.6K
 * Total Submissions: 260.5K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        for (auto p1 = l1; p1 != nullptr; p1 = p1->next) {
            st1.emplace(p1->val);
        }

        for (auto p2 = l2; p2 != nullptr; p2 = p2->next) {
            st2.emplace(p2->val);
        }

        int carry = 0;
        ListNode* res = nullptr;
        while (!st1.empty() || !st2.empty() || carry != 0) {
            auto n1 = st1.empty() ? 0 : st1.top();
            if (!st1.empty()) st1.pop();

            auto n2 = st2.empty() ? 0 : st2.top();
            if (!st2.empty()) st2.pop();

            int t = n1 + n2 + carry;
            carry = t / 10;
            
            auto p = new ListNode(t % 10);
            p->next = res;
            res = p;
        }

        return res;
    }
};
// @lc code=end

