/*
Problem: Spiral Matrix
LeetCode: 54
Difficulty: Medium
Link: https://leetcode.com/problems/spiral-matrix/

---

Approach:
We present two solutions for this problem:
1. Boundary Contraction (Optimal): We maintain four boundaries (`rs`, `re`, `cs`, `ce`) and shrink them after traversing the perimeter. We use conditional guards (`rs < re` and `cs < ce`) to avoid duplicate traversals in single-row/single-column matrix cases.
2. Element Counter (Alternative/Slightly Worse): Instead of conditional guards, we check if the number of collected elements has reached the total elements (`ans.size() < total`) inside every loop condition.

Time Complexity:  O(M * N) where M is the number of rows and N is the number of columns (for both solutions)
Space Complexity: O(1) extra space (excluding the output array)

---

Edge Cases:
- The matrix is 1x1. Handled correctly by boundary check / element counter conditions.
- A single-row matrix (1xN) or a single-column matrix (Mx1). Handled by conditional guards in Solution 1, and size check in Solution 2.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

/*
// Solution 2: Element Counter (Alternative/Slightly Worse)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = 0;
        int re = matrix.size() - 1;
        int cs = 0;
        int ce = matrix[0].size() - 1;
        vector<int> ans;
        int total = matrix.size() * matrix[0].size();

        while (ans.size() < total) {
           
            for (int i = cs; i <= ce && ans.size() < total; i++) {
                ans.push_back(matrix[rs][i]);
            }

            for (int i = rs + 1; i <= re && ans.size() < total; i++) {
                ans.push_back(matrix[i][ce]);
            }

            for (int i = ce - 1; i >= cs && ans.size() < total; i--) {
                ans.push_back(matrix[re][i]);
            }

            for (int i = re - 1; i > rs && ans.size() < total; i--) {
                ans.push_back(matrix[i][cs]);
            }
            rs++; ce--; re--; cs++;
        }
        return ans;
    }
};
*/

// Solution 1: Boundary Contraction (Optimal)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = 0;
        int re = matrix.size() - 1;
        int cs = 0;
        int ce = matrix[0].size() - 1;
        vector<int> ans;
        while (rs <= re && cs <= ce) {
            for (int i = cs; i <= ce; i++) {
                ans.push_back(matrix[rs][i]);
            }
            for (int i = rs + 1; i <= re; i++) {
                ans.push_back(matrix[i][ce]);
            }
            if (rs < re) {
                for (int i = ce - 1; i >= cs; i--) {
                    ans.push_back(matrix[re][i]);
                }
            }
            if (cs < ce) {
                for (int i = re - 1; i > rs; i--) {
                    ans.push_back(matrix[i][cs]);
                }
            }

            rs++;
            ce--;
            re--;
            cs++;
        }
        return ans;
    }
};
