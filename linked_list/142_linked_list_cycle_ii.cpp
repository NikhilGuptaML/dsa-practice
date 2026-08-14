/*
Problem: Linked List Cycle II
LeetCode: 142
Difficulty: Medium
Link: https://leetcode.com/problems/linked-list-cycle-ii/

---

Approach:
Uses Floyd's Cycle-Finding Algorithm with two pointers (`slow` and `fast`) to detect if a cycle exists. Once a collision occurs, `slow` is reset to `head` while `fast` remains at the collision point. Advancing both pointers one step at a time guarantees they will meet at the start node of the cycle due to the mathematical equivalence between the distance from the head to the cycle entrance and the distance around the cycle from the collision point.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Empty list (`head == nullptr`) or single node without cycle: The loop condition fails, returning `NULL`.
- Entire list is a single cycle (head is the entry node): Collision point equals `head`, so the second loop finishes immediately and returns `head`.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    break;
                }
            } else {
                return NULL;
            }
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
