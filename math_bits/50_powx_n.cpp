/*
Problem: Pow(x, n)
LeetCode: 50
Difficulty: Medium
Link: https://leetcode.com/problems/powx-n/

---

Approach:
Uses recursive binary exponentiation (divide and conquer) to compute x^n. If n is even, x^n = (x * x)^(n / 2). If n is odd and positive, returns x * myPow(x, n - 1). If n is odd and negative, returns (1 / x) * myPow(x, n + 1), avoiding integer overflow when n = INT_MIN.

Time Complexity:  O(log N)
Space Complexity: O(log N) recursion call stack space

---

Edge Cases:
- n = 0: Base case returns 1.0.
- Negative powers (n < 0): Handled using 1 / x * myPow(x, n + 1) for odd n, seamlessly handling INT_MIN without negation overflow.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } else {
            if (n > 0)
                return x * myPow(x, n - 1);
            else
                return 1 / x * myPow(x, n + 1);
        }
    }
};
