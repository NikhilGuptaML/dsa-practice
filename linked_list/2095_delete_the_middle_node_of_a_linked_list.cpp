/*
Problem: Delete the Middle Node of a Linked List
LeetCode: 2095
Difficulty: Medium
Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

---

Approach:
Uses the fast and slow pointer (Tortoise and Hare) technique to find the middle node of the linked list in a single pass. The `fast` pointer moves two steps while `slow` moves one step. A `prev` pointer tracks the node immediately preceding `slow`. Once `fast` reaches the end (`nullptr`), `slow` points to the middle node, and `prev->next = slow->next` deletes it.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Single node list (`head->next == nullptr`): Returns `nullptr` since removing the only node leaves an empty list.
- Two-node list: `slow` points to the second node, `prev` points to the first node; `prev->next` becomes `nullptr`, leaving a single node.
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (head->next == nullptr) {
            return nullptr;
        } else {
            prev->next = slow->next;
        }
        return head;
    }
};
