/*
Problem: Copy List with Random Pointer
LeetCode: 138
Difficulty: Medium
Link: https://leetcode.com/problems/copy-list-with-random-pointer/

---

Approach:
Provides three implementations for deep-copying a linked list with random pointers:
1. Solution 1 (In-Place Interleaving - Loop Variant 1): Interleaves cloned nodes directly after original nodes (original->next = clone). Sets random pointers using temp->next->random = temp->random->next, then unweaves the lists using a while(true) loop.
2. Solution 2 (In-Place Interleaving - Loop Variant 2): Uses the same 3-pass interleaving technique, with a while(temp != NULL) condition for unweaving the lists.
3. Solution 3 (Hash Map Approach): Uses unordered_map<Node*, Node*> to map original nodes to newly created copy nodes. In a second pass, assigns random pointers via map lookups.

Time Complexity:  O(N) for all solutions
Space Complexity: O(1) auxiliary space for Solutions 1 & 2; O(N) auxiliary space for Solution 3

---

Edge Cases:
- Empty list (head == nullptr): Handled immediately by returning nullptr.
- random pointer is nullptr: Handled explicitly in all approaches without dereferencing null pointers.
- Circular or self-referencing random pointers: Correctly cloned via pointer offset / hash map mapping.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1: In-Place Interleaving (Loop Variant 1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return nullptr;
        }
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }
            temp = temp->next->next;
        }
        Node* newHead = head->next;
        temp = head;
        Node* alt = newHead;
        while(true){
            temp->next = temp->next->next;
            temp = temp->next;
            if(temp==NULL) break;
            alt->next = temp->next;
            alt = alt->next;
        }
        return newHead;
    }
};

// Solution 2: In-Place Interleaving (Loop Variant 2)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return nullptr;
        }
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }
            temp = temp->next->next;
        }
        Node* newHead = head->next;
        temp = head;
        Node* alt = newHead;
        while(temp!=NULL){
            temp->next = temp->next->next;
            if(alt->next!=NULL){
                alt->next = alt->next->next;
            }
            temp = temp->next;
            alt = alt->next;
        }
        return newHead;
    }
};

// Solution 3: Hash Map Approach

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* dummy = new Node(0);
        Node* altTemp = dummy;
        Node* temp = head;
        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            altTemp->next = newNode;
            map[temp] = newNode;
            temp = temp->next;
            altTemp = altTemp->next;
        }
        Node* newHead = dummy->next;
        delete dummy;
        temp = head;
        altTemp = newHead;
        while(temp!=nullptr){
            if(map.count(temp->random)){
                altTemp->random = map[temp->random];
            }else{
                altTemp->random = nullptr;
            }
            temp = temp->next;
            altTemp = altTemp->next;
        }
        return newHead;
    }
};
