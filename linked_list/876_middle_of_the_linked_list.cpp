/*
Problem: Middle of the Linked List
LeetCode: 876
Difficulty: Easy
Link: https://leetcode.com/problems/middle-of-the-linked-list/

---

Approach:
Uses the fast and slow two-pointer technique to find the middle node of a singly-linked list. The `slow` pointer advances one node at a time while the `fast` pointer advances two nodes at a time. When `fast` reaches the end of the list, `slow` points to the middle.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Odd-length list: `fast->next` becomes NULL, leaving `slow` at the exact middle element.
- Even-length list: `fast` becomes NULL, leaving `slow` at the second middle element as specified.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
