/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (35.34%)
 * Likes:    1747
 * Dislikes: 109
 * Total Accepted:    253.9K
 * Total Submissions: 691.9K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto dummy = new ListNode(-1);
        dummy->next = head;

        auto pre = dummy;

        bool f = false;
        while (pre->next != nullptr) {
            auto cur = pre->next;

            while (cur && cur->val == pre->next->val) {
                cur = cur->next;
            }

            if (pre->next->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur;
            }
        }

        return dummy->next;
    }
};
// @lc code=end

