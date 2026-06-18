/*
Problem: Pascal's Triangle
LeetCode: 118
Difficulty: Easy
Link: https://leetcode.com/problems/pascals-triangle/

---

Approach:
We generate Pascal's triangle dynamically row by row.
We initialize the triangle with the first row `{{1}}`.
To generate each subsequent row `current` (from 2 up to `numRows`), we initialize a vector of size `current` filled with 1s.
Then, we calculate each middle element at index `i` (from 1 to `current - 2`) as the sum of the elements at indices `i - 1` and `i` from the previous row (`ans.back()`).

Time Complexity:  O(numRows^2) since we generate and fill every element in the triangle
Space Complexity: O(1) auxiliary space (excluding the memory used to store the output triangle)

---

Edge Cases:
- `numRows = 1`. The loop is bypassed entirely, and we correctly return `{{1}}`.
- Minimum constraints (`numRows = 30`). No integer overflow occurs because the largest element in the 30th row of Pascal's triangle is 29 choose 14 = 77,558,760, which easily fits within a standard 32-bit signed integer.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int st = 1;
        int end = 0;
        vector<vector<int>> ans = {{1}};
        int current = 2;
        while (current <= numRows) {
            vector<int> arr(current, 1);
            end = current - 1;
            for (int i = st; i < end; i++) {
                arr[i] = ans.back()[i - 1] + ans.back()[i];
            }
            ans.push_back(arr);
            current++;
        }
        return ans;
    }
};
