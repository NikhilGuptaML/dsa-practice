/*
Problem: Delete Node in a Linked List
LeetCode: 237
Difficulty: Medium
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

---

Approach:
Deletes a target node given only access to that node by copying the value of the next node (`node->next->val`) into the target node, and then bypassing the next node by pointing `node->next` to `node->next->next`.

Time Complexity:  O(1)
Space Complexity: O(1)

---

Edge Cases:
- Node is the head node: Works identically by overwriting head's value with second node's value and bypassing second node.
- Node is adjacent to the tail node: Overwrites node value with tail node's value and sets `node->next` to `NULL`.
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
    void deleteNode(ListNode* node) {

        node->val = node->next->val;
        node->next = node->next->next;

        return;
        
    }
};
