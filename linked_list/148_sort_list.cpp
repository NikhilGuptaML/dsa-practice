/*
Problem: Sort List
LeetCode: 148
Difficulty: Medium
Link: https://leetcode.com/problems/sort-list/

---

Approach:
Applies Merge Sort recursively on the singly-linked list. It splits the list into two halves around the midpoint using `splitAtMid` (fast and slow pointer technique), recursively sorts both sublists using `sortList`, and merges the sorted sublists using `merge` in-place by rewiring node pointers.

Time Complexity:  O(N log N)
Space Complexity: O(log N) stack space due to recursion

---

Edge Cases:
- Empty list (`head == NULL`) or single-node list (`head->next == NULL`): Base case returns `head` immediately.
- Two-node list: Splits into two single nodes, sorts, and merges them correctly.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1: Initial Implementation

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
    ListNode* merge(ListNode* head, ListNode* head2) {
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        if(head->val<=head2->val){
            newHead = head;
            tail = head;
            head = head->next;
        }else{
            newHead = head2;
            tail = newHead;
            head2= head2->next;
        }
        while(head!=NULL && head2!=NULL){
            if(head->val<=head2->val){
                tail->next = head;
                tail = tail->next;
                head = head->next;
            }else{
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }
        while(head!=NULL){
            tail->next = head;
                tail = tail->next;
                head = head->next;
        }
        while(head2!=NULL){
            tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
        }
        tail->next = NULL;
        return newHead;
    }
    ListNode* splitAtMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* head2 = splitAtMid(head);

        head = sortList(head);
        head2 = sortList(head2);

        return merge(head, head2);
    }
};

// Solution 2: AI Improvised / Optimized Version

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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // 1. Traverse and merge while BOTH lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // 2. Attach the remaining nodes in O(1) time
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }

    ListNode* splitAtMid(ListNode* head) {
        // Base case fallback
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        // Start fast one step ahead so slow stops right BEFORE the exact middle
        ListNode* fast = head->next; 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 'mid' is the start of the second half
        ListNode* mid = slow->next; 
        
        // Sever the connection to split the list in two
        slow->next = nullptr; 

        return mid;
    }

    ListNode* sortList(ListNode* head) {
        // Base case: 0 or 1 node is already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* mid = splitAtMid(head);

        // Recurse on both halves
        head = sortList(head);
        mid = sortList(mid);

        // Merge the sorted halves
        return merge(head, mid);
    }
};
