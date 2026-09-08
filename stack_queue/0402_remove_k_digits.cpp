/*
Problem: Remove K Digits
LeetCode: 402
Difficulty: Medium
Link: https://leetcode.com/problems/remove-k-digits/

---

Approach:
Uses a greedy monotonic increasing stack. To construct the smallest possible number, smaller digits must be placed in higher significant positions (leftmost). Iterates through `num` and pops digits from the stack whenever `num[i] < st.top()` and `k > 0`. If `k` removals remain after traversing the string, pops remaining digits from the stack top. Finally, converts the stack to a string, reverses it, and strips leading zeros.

Time Complexity:  O(N) where N = num.size()
Space Complexity: O(N) for the monotonic stack and output string construction

---

Edge Cases:
- `k >= num.size()` (all digits removed, returns "0").
- Result contains leading zeroes (e.g., "10200" with k=1 -> "0200" -> strips leading zeros to return "200").
- Result becomes empty after stripping leading zeroes (returns "0").
- Monotonically increasing input string (e.g. "12345" with k=2 -> pops from the tail to return "123").
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }

        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && num[i] < st.top()) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        string temp;

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());


        int i = 0;
        while (i < temp.size() && temp[i] == '0') {
            i++;
        }

        if (i == temp.size()) {
            return "0";
        }

        return temp.substr(i);
    }
};
