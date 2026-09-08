/*
Problem: Asteroid Collision
LeetCode: 735
Difficulty: Medium
Link: https://leetcode.com/problems/asteroid-collision/

---

Approach:
Simulates collisions using a stack. Moving right asteroids (positive values) are pushed directly onto the stack. When a moving left asteroid (negative value) appears, it collides with right-moving asteroids (`st.top() > 0`) on top of the stack. If the stack top is smaller, it explodes (popped). If equal, both explode (`des = true`). If stack top is larger, the current asteroid explodes (`des = true`). If the current asteroid survives all collisions, it is pushed onto the stack.

Time Complexity:  O(N) where N = ast.size()
Space Complexity: O(N) for stack storage in worst case

---

Edge Cases:
- Asteroids moving in opposite directions away from each other (e.g. [-2, -1, 1, 2]) where no collisions occur.
- Equal magnitude asteroids colliding (e.g. [8, -8]) destroying both.
- Large negative asteroid destroying multiple smaller positive asteroids in sequence (e.g. [5, 10, -15]).
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for (int i = 0; i < ast.size(); i++) {
            bool des = false;
            while (!st.empty() && st.top() > 0 && ast[i] < 0) {
                if (st.top() < abs(ast[i])) {
                    st.pop();
                } else if (st.top() == abs(ast[i])) {
                    st.pop();
                    des = true;
                    break;
                } else {
                    des = true;
                    break;
                }
            }
            if (!des) {
                st.push(ast[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size() - 1;i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
