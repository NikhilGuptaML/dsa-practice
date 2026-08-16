/*
Problem: Intersection of Two Linked Lists
LeetCode: 160
Difficulty: Easy
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

---

Approach:
Solves the problem using two pointer traversal. Pointers `tempA` and `tempB` traverse lists `A` and `B` respectively. When either pointer reaches `NULL`, it switches to the head of the opposite list. This aligns their traversal paths after equalizing the total distance traveled ($M + N$), causing them to collide at the intersection node if one exists, or reach `NULL` simultaneously if no intersection exists.

Time Complexity:  O(M + N)
Space Complexity: O(1) for two-pointer approach (O(M + N) for hash set approach)

---

Edge Cases:
- No intersection: Pointers redirect once and both reach `NULL` simultaneously at the end of their second path.
- Intersection at the head: Pointers equal each other immediately, returning the head node.
- Differing lengths: Equalized after switching pointers to the opposite list's head.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1: Hash Set Approach (Sequential)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visit;
        while(headA!=NULL){
            visit.insert(headA);
            headA = headA->next;
        }
        while(headB!=NULL){
            if(visit.count(headB)){
                return headB;
            }
            visit.insert(headB);
            headB = headB->next;
        }
        return nullptr;

    }
};

// Solution 2: Hash Set Approach (Interleaved)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visit;

        while(headA!=NULL && headB!=NULL){
            if(visit.count(headA)){
                return headA;
            }
            visit.insert(headA);
            if(visit.count(headB)){
                return headB;
            }
            
            visit.insert(headB);
            headA = headA->next;
            headB = headB->next;

        }
        while(headA!=NULL){
            if(visit.count(headA)){
                return headA;
            }
            visit.insert(headA);
            headA = headA->next;
        }
        while(headB!=NULL){
            if(visit.count(headB)){
                return headB;
            }
            visit.insert(headB);
            headB = headB->next;
        }
        return nullptr;

    }
};

// Solution 3: Optimal Two-Pointer Approach

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != tempB) {
            if (tempA == NULL) {
                tempA = headB;
            } else {
                tempA = tempA->next;
            }

            if (tempB == NULL) {
                tempB = headA;
            } else {
                tempB = tempB->next;
            }
        }

        return tempA;
    }
};
