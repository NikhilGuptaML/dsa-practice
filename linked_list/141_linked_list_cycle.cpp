/*
Problem: Linked List Cycle
LeetCode: 141
Difficulty: Easy
Link: https://leetcode.com/problems/linked-list-cycle/

---

Approach:
Uses Floyd's Cycle-Finding Algorithm (Tortoise and Hare technique) with two pointers (`slow` and `fast`) moving at different speeds. The fast pointer advances two steps while the slow pointer advances one step at a time. If a cycle exists, the fast pointer will eventually catch up and meet the slow pointer; otherwise, the fast pointer reaches the end (`NULL`), indicating no cycle.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Empty list (`head == NULL`): Returns `false` immediately.
- Single node without cycle: `fast->next` is `NULL`, condition fails and returns `false`.
- Two-node cycle: Fast pointer loops back and meets slow pointer, returning `true`.
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head==NULL){
            return false;
        }
        while(true){
            
            
            if(fast->next!=NULL && fast->next->next!=NULL){
                fast = fast->next->next;
            }else{
                return false;
            }
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
