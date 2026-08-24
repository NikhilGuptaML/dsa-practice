/*
Problem: Rotate List
LeetCode: 61
Difficulty: Medium
Link: https://leetcode.com/problems/rotate-list/

---

Approach:
Computes the total length of the linked list while keeping track of the tail node. Normalizes k using k % length. If k != 0, traverses to the (length - k)-th node to locate the new tail. Breaks the link at this node, connects the original tail to the original head, and updates head to the node after the new tail.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Empty list (head == nullptr) or k = 0: Returned immediately without performing any operations.
- k is a multiple of list length (k % length == 0): Handled by the modulo reduction, leaving the list unchanged.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k){
            return head;
        }
        int length = 0;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != NULL) {
            length++;
            prev = temp;
            temp = temp->next;
        }
        ListNode* tail = prev;
        k = k % length;
        //till this 
        if (k != 0) {
            int tem = length - k;
            temp = head;
            for(int i = 1;i<tem;i++){
                temp = temp -> next;
            }
            ListNode* suc = temp->next;
            temp->next = NULL;
            tail->next = head;
            head = suc;
        }
        return head;
    }
};
