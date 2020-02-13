/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (39.21%)
 * Likes:    2105
 * Dislikes: 103
 * Total Accepted:    230.6K
 * Total Submissions: 587.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* merge(ListNode* l, ListNode* r)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (l != nullptr && r != nullptr) {
            if (l->val <= r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }

        if (l == nullptr) cur->next = r;
        if (r == nullptr) cur->next = l;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = head;

        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // cut
        pre->next = nullptr;

        ListNode* l = sortList(head);
        ListNode* r = sortList(slow);

        return merge(l, r);        
    }
};
// @lc code=end

