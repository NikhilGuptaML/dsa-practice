/*
Problem: Sum of Subarray Ranges
LeetCode: 2104
Difficulty: Medium
Link: https://leetcode.com/problems/sum-of-subarray-ranges/

---

Approach:
Uses the mathematical property: Sum of Subarray Ranges = (Sum of Subarray Maximums) - (Sum of Subarray Minimums).
Maintains two monotonic stacks simultaneously:
- `stMin` (monotonic increasing stack) to count how many subarrays have `nums[popped]` as their minimum element.
- `stMax` (monotonic decreasing stack) to count how many subarrays have `nums[popped]` as their maximum element.
For each element, the number of subarrays where it is the min/max is given by `lD * rD` (left distance * right distance). Its total contribution is `(lD * rD) * nums[popped]`, added for maxes and subtracted for mins.

Time Complexity:  O(N) single-pass with stack flush where N = nums.size()
Space Complexity: O(N) auxiliary space for two monotonic stacks

---

Edge Cases:
- Single-element vector (range = 0, loop terminates cleanly).
- Duplicate elements in `nums` (handled correctly by strict inequalities in monotonic stack conditions).
- Large integer products causing overflow (prevented by `(long long)lD * rD * nums[popped]`).
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;

        stack<int> stMin;
        stack<int> stMax;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (!stMin.empty() && nums[i] < nums[stMin.top()]) {
                int popped = stMin.top();
                stMin.pop();

                int lD = stMin.empty() ? popped + 1 : (popped - stMin.top());
                int rD = i - popped;

                ans -= (long long)lD * rD * nums[popped];
            }
            stMin.push(i);

            while (!stMax.empty() && nums[i] > nums[stMax.top()]) {
                int popped = stMax.top();
                stMax.pop();

                int lD = stMax.empty() ? popped + 1 : (popped - stMax.top());
                int rD = i - popped;

                ans += (long long)lD * rD * nums[popped];
            }
            stMax.push(i);
        }

        while (!stMin.empty()) {
            int popped = stMin.top();
            stMin.pop();

            int lD = stMin.empty() ? popped + 1 : (popped - stMin.top());
            int rD = n - popped;

            ans -= (long long)lD * rD * nums[popped];
        }

        while (!stMax.empty()) {
            int popped = stMax.top();
            stMax.pop();

            int lD = stMax.empty() ? popped + 1 : (popped - stMax.top());
            int rD = n - popped;

            ans += (long long)lD * rD * nums[popped];
        }
        return ans;
    }

};
