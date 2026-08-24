/*
Problem: Divide Two Integers
LeetCode: 29
Difficulty: Medium
Link: https://leetcode.com/problems/divide-two-integers/

---

Approach:
Divides two integers without using multiplication, division, or modulo operators using bitwise shifting:
1. Solution 1 (Dynamic Bit Shifting): Dynamically finds the maximum left-shift count `cnt` such that `(d << (cnt + 1)) <= n`, subtracts `(d << cnt)` from `n`, and adds `(1LL << cnt)` to the answer.
2. Solution 2 (Fixed 32-Bit Iteration): Iterates from bit position 31 down to 0, checking if `(n >> i) >= d` to construct the quotient bit by bit in fixed 32 steps.

Time Complexity:  O(log^2 N) for Solution 1; O(32) = O(1) for Solution 2
Space Complexity: O(1)

---

Edge Cases:
- 32-bit overflow (dividend == INT_MIN and divisor == -1): Returns INT_MAX.
- Negative dividend or divisor: Handled via sign flags and casting to long long to prevent abs(INT_MIN) overflow.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1: Dynamic Bit Shifting

class Solution {
public:
    int divide(int dividend, int divisor) {

        bool sign = true;

        if ((dividend < 0 && divisor > 0) ||
            (dividend > 0 && divisor < 0)) {
            sign = false;
        }

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        if (n == d) {
            return sign ? 1 : -1;
        }

        long long ans = 0;

        while (n >= d) {
            int cnt = 0;

            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        if (!sign) ans = -ans;

        if (ans > INT_MAX)
            return INT_MAX;

        return (int)ans;
    }
};

// Solution 2: Fixed 32-Bit Bitwise Iteration

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit overflow edge cases
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Determine result sign
        bool isPositive = (dividend < 0) == (divisor < 0);

        // Cast to long long to prevent abs(INT_MIN) overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        // Subtract divisor shifted by powers of 2 from highest to lowest
        for (int i = 31; i >= 0; i--) {
            if ((n >> i) >= d) {
                quotient += (1LL << i);
                n -= (d << i);
            }
        }

        return isPositive ? quotient : -quotient;
    }
};
