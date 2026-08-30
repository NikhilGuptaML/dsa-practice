/*
Problem: Valid Parentheses
LeetCode: 20
Difficulty: Easy
Link: https://leetcode.com/problems/valid-parentheses/

---

Approach:
Uses a stack to track opening brackets in LIFO order. When an opening bracket is encountered, it is pushed onto the stack. When a closing bracket is encountered, the top of the stack is checked to verify it forms a matching pair; if so, it is popped, otherwise the string is invalid. The string is valid if the stack is empty at the end.

Time Complexity:  O(N)
Space Complexity: O(N)

---

Edge Cases:
- Empty stack when a closing bracket is encountered (e.g., ")(").
- Unmatched opening brackets remaining in stack at the end (e.g., "(((").
- Mismatched bracket types (e.g., "(]").
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                continue;
            }
            if (st.empty()) {
                return false;
            }
            char temp = st.top();
            if (st.top() == '(' && s[i] == ')' ||
                st.top() == '[' && s[i] == ']' ||
                st.top() == '{' && s[i] == '}') {
                st.pop();
            } else {
                return false;
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};
