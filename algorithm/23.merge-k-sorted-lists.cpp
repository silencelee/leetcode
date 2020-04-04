/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.15%)
 * Likes:    2673
 * Dislikes: 171
 * Total Accepted:    417.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto myCmp = [](const ListNode* n1, const ListNode* n2) {
            return n1->val > n2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(myCmp)> heap(myCmp);

        for (auto node : lists) {
            if (node != nullptr) heap.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!heap.empty()) {
            auto node = heap.top();
            heap.pop();
            if (node->next != nullptr) heap.push(node->next);
            cur->next = node;
            cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

