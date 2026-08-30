/*
Problem: Min Stack
LeetCode: 155
Difficulty: Medium
Link: https://leetcode.com/problems/min-stack/

---

Approach:
Maintains two parallel stacks (or dynamic arrays): `s` for storing elements and `minSt` for tracking the minimum element at each stack depth. Every `push` operation inserts the new value into `s` and the current minimum into `minSt`. Every `pop` operation removes elements from both, allowing `top` and `getMin` to execute in constant O(1) time.

Time Complexity:  O(1) for push, pop, top, and getMin
Space Complexity: O(N) auxiliary space to track minimums per stack state

---

Edge Cases:
- Empty stack initialization and subsequent pushes after clearing all elements.
- Pushing duplicate minimum values or negative numbers.
- Minimum element equal to INT_MIN or extreme integer values.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1

class MinStack {
private:
    int min;
    vector<int> s;
    vector<int> minSt;

public:
    MinStack() {
        min = INT_MAX;
    }

    void push(int value) {
        s.push_back(value);
        if(value<min){
            min = value;
        }
        minSt.push_back(min);
    }

    void pop() {
        s.pop_back();
        minSt.pop_back();
        if(minSt.empty()){
            min = INT_MAX;
            return;
        }
        min = minSt.back();
    }

    int top() {
        int size = s.size();

        return s[size-1];
    }

    int getMin() {
        int size = s.size();

        return minSt[size-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Solution 2

class MinStack {
private:
    vector<int> s;
    vector<int> minSt;

public:
    MinStack() {}

    void push(int value) {
        s.push_back(value);

        if (minSt.empty()) {
            minSt.push_back(value);
        } else {
            minSt.push_back(min(value, minSt.back()));
        }
    }

    void pop() {
        s.pop_back();
        minSt.pop_back();
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return minSt.back();
    }
};
