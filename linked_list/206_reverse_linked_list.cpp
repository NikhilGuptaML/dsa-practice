/*
Problem: Reverse Linked List
LeetCode: 206
Difficulty: Easy
Link: https://leetcode.com/problems/reverse-linked-list/

---

Approach:
Iteratively reverses a singly-linked list using three pointers (`prev`, `temp`, and `fut`). In each iteration, it updates `temp->next` to point to `prev`, then advances both `prev` and `temp` forward until reaching the end of the list.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Empty list (`head == NULL`): The while loop is skipped and `prev` (which is NULL) is returned.
- Single node list: The loop runs once, setting `next` to NULL, and returns the head node.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* fut = temp->next; 
            temp->next = prev;          
            prev = temp;                
            temp = fut;                 
        }

        return prev; 
    }
};
