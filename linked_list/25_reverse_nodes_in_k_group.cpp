/*
Problem: Reverse Nodes in k-Group
LeetCode: 25
Difficulty: Hard
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

---

Approach:
Calculates the total length of the list to determine how many full groups of size $K$ exist (`count = length / k`). Uses a dummy node and a helper function `reverse` to iteratively reverse each group of $K$ nodes in-place, updating pointer connections between `groupPrev`, the newly reversed sublist, and the remaining nodes. Remaining nodes at the end (less than $K$) are left untouched.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- $K = 1$ or empty list (`!head`): Base condition returns `head` immediately without modifications.
- List length $< K$: `count = 0`, no groups are reversed, returning the original list intact.
- Leftover nodes $< K$ at the end: Left unreversed per problem requirements.
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
    ListNode* reverse(ListNode* head, ListNode* groupPrev, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head->next = curr;
        groupPrev->next = prev;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        int count = length / k;

        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        ListNode* curr = head;

        while (count > 0) {
            groupPrev = reverse(curr, groupPrev, k);
            curr = groupPrev->next;
            count--;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
