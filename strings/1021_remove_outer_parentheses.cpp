/*
# NOTE: Categorised under strings because it is part of the string section in Striver's sheet

Problem: Remove Outermost Parentheses
LeetCode: 1021
Difficulty: Easy
Link: https://leetcode.com/problems/remove-outermost-parentheses/

---

Approach:
We traverse the string and maintain a balance counter `op` that tracks the nesting depth of parentheses, acting as a lightweight simulation of a stack pointer.
When we see '(', we add it to our result string only if the depth is already greater than 0 (which means it is not the outermost opening parenthesis), and then we increment the depth.
When we see ')', we decrement the depth first (or check `op > 1` before decrementing), and add it to our result string only if the depth is still greater than 0 (which means it is not the outermost closing parenthesis).

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- Minimal input such as "()", which should return "" as the outer parentheses are removed.
- Multiple adjacent primitive parenthesis groups like "()()", which should return "" because each outer group is stripped.
- Highly nested parenthetical groups like "(((())))", which correctly strips only the outermost pair to return "((()))".
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int op = 0;
        
        for (char c : s) {
            if (c == '(') {
                
                if (op > 0) {
                    ans += c; 
                }
                op++;
            } else {
                
                if (op > 1) {
                    ans += c;
                }
                op--;
            }
        }
        
        return ans;
    }
};
