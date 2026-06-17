/*
Problem: Matrix Diagonal Sum
LeetCode: 1572
Difficulty: Easy
Link: https://leetcode.com/problems/matrix-diagonal-sum/

---

Approach:
We compute the sum of the two diagonals of a square matrix by traversing them individually.
One pass summates the primary diagonal from the top-left to the bottom-right, and a second pass summates the secondary diagonal from the top-right to the bottom-left.
To avoid double-counting the center element when the matrix size is odd, we subtract the center element from the final sum after the two passes.

Time Complexity:  O(N) where N is the matrix dimension (number of rows/columns)
Space Complexity: O(1)

---

Edge Cases:
- The matrix has a size of 1x1. The algorithm traverses the single element in both loops and correctly subtracts the duplicate count of that element since size - 1 (0) is even.
- The matrix has an even size (e.g., 2x2). The diagonals do not intersect at a single central element, and the subtraction step is correctly bypassed as size - 1 is odd.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int size = mat.size();
      int sum = 0;
      for(int i = 0,j = 0;i<size; ){
        sum += mat[i][j];
        i++;j++;
      }

      for(int i = 0,j = size-1;i<size; ){
        sum += mat[i][j];
        i++;j--;
      }
    int common = size-1;
      if(common % 2 == 0){
        common/=2;
        sum-=mat[common][common];
      }  
      return sum;
    }
};
