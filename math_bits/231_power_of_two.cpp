/*
Problem: Power of Two
LeetCode: 231
Difficulty: Easy
Link: https://leetcode.com/problems/power-of-two/

---

Approach:
Uses bit manipulation (n & (n - 1)). A positive integer n is a power of two if and only if it has exactly one set bit in its binary representation. Subtracting 1 flips all bits after and including the set bit, so (n & (n - 1)) clears the lowest set bit and equals 0.

Time Complexity:  O(1)
Space Complexity: O(1)

---

Edge Cases:
- Non-positive numbers (n <= 0): Handled immediately by returning false since negative numbers and zero are not powers of two.
- Maximum integer power of two (2^30): Handled correctly without integer overflow.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        return (n & (n - 1)) == 0;
    }
};
