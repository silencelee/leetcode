/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (37.14%)
 * Likes:    1789
 * Dislikes: 118
 * Total Accepted:    239K
 * Total Submissions: 643.4K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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

/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pPreM = dummy;
        ListNode* pN = dummy;

        for (int i = 1; i < m; ++i) pPreM = pPreM->next;
        for (int i = 1; i <= n; ++i) pN = pN->next;

        ListNode* pM = pPreM->next;
        ListNode* pAfterN = pN->next;

        ListNode* pre = pM;
        ListNode* cur = pM->next;
        while (cur != pAfterN) {
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }

        pM->next = pAfterN;
        pPreM->next = pN;

        return dummy->next;
    }
};
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr || head->next == nullptr || m == n) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;

        for (int i = 1; i < m; ++i) pre = pre->next;

        ListNode* cur = pre->next;
        for (int i = m; i < n; ++i) {
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        } 

        return dummy->next;
    }
};
// @lc code=end

