/*
Problem: Odd Even Linked List
LeetCode: 328
Difficulty: Medium
Link: https://leetcode.com/problems/odd-even-linked-list/

---

Approach:
Groups all nodes with odd indices together followed by nodes with even indices, preserving their relative order. Uses two pointers (`odd` and `even`) and stores `evenHead` to append at the end. Iteratively updates `odd->next` to point to the next odd node (`even->next`) and `even->next` to the next even node (`odd->next`), advancing both pointers until all nodes are reordered, then links the end of the odd list to `evenHead`.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Empty list (`head == NULL`): Handled by base check, returning `nullptr` / `head`.
- Single node or two nodes: Handled without error, leaving relative order intact and attaching `evenHead`.
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return nullptr;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even!=NULL && even->next!=NULL){
            odd->next = even -> next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL|| head->next == NULL || head->next->next==NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(true){
            odd->next = odd->next->next;
            odd = odd->next;
            if(odd->next==NULL){
                odd->next = evenHead;
                even->next = NULL;
                break;
            }
            even->next = even->next->next;
            even=even->next;
            if(even->next==NULL){
                odd->next = evenHead;
                break;
            }
        }
        return head;
    }
};
