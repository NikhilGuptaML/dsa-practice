/*
Problem: Add Two Numbers
LeetCode: 2
Difficulty: Medium
Link: https://leetcode.com/problems/add-two-numbers/

---

Approach:
Simulates digit-by-digit addition from least significant to most significant digit while maintaining a `carry` variable. Iterates through `l1` and `l2` using a dummy head node to attach new nodes containing `sum % 10` and updates `carry = sum / 10`.

NOTE: It is possible to consolidate the three separate while loops (and final carry check) into a single while loop (`while (l1 != nullptr || l2 != nullptr || carry != 0)`) using if statements to add non-null values dynamically.

Time Complexity:  O(max(N, M))
Space Complexity: O(max(N, M)) for the output linked list

---

Edge Cases:
- Lists of unequal length: Processed by continuing addition with the remaining nodes of the longer list and `carry`.
- Final carry remaining (e.g., 5 + 5 = 10): Appends an extra node for the final non-zero `carry`.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        int sum = 0;
        while (l1 != nullptr && l2 != nullptr) {

            sum = l1->val + l2->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            sum = l1->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
            carry = sum / 10;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            sum = l2->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
            carry = sum / 10;
            l2 = l2->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return dummy->next;
    }
};
