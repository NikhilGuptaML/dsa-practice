/*
Problem: Remove Nth Node From End of List
LeetCode: 19
Difficulty: Medium
Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

---

Approach:
Uses a two-pointer sliding window technique where pointers `temp` and `prev` are separated by a gap of `n` nodes. As `temp` traverses to the end of the list, `prev` advances alongside it, while `prePrev` tracks the node right before `prev`. Once `temp` reaches `NULL`, `prev` points to the $N$-th node from the end, allowing `prePrev->next = prev->next` to remove it in a single pass.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Removing the head node ($N$ equals list length): `prePrev` remains `nullptr`, so `head` updates to `head->next`.
- Single-node list ($N = 1$): `prePrev` is `nullptr`, returning `nullptr`.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = head;
        ListNode* prePrev = NULL;
        int gap = 0;
        while (temp!= NULL) {
            temp= temp -> next;
            if (gap >= n){
                prePrev = prev;
                prev = prev->next;
            }
            gap++;
        }
        if (prePrev==nullptr) {
            head = head->next;
        } else {
            prePrev->next = prev->next;
        }
        return head;
    }
};
