/*
Problem: Search a 2D Matrix II
LeetCode: 240
Difficulty: Medium
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

---

Approach:
We use a staircase search algorithm starting from the top-right corner of the matrix:
- If the current element is equal to the target, we return true.
- If the current element is greater than the target, since the column is sorted in ascending order from top to bottom, all elements below the current element in this column are also greater than the target. Thus, we eliminate this column by moving left (decrementing the column index).
- If the current element is less than the target, since the row is sorted in ascending order from left to right, all elements to the left of the current element in this row are also less than the target. Thus, we eliminate this row by moving down (incrementing the row index).

Time Complexity:  O(M + N) where M is the number of rows and N is the number of columns
Space Complexity: O(1)

---

Edge Cases:
- The matrix is 1x1. The search immediately evaluates the only element and terminates.
- The target is out of bounds (smaller than matrix[0][0] or larger than matrix[M-1][N-1]). The pointers correctly traverse out of the matrix boundaries, and the function returns false.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        pair<int, int> mid = {0 , matrix[0].size()-1};
        while(mid.first<matrix.size() && mid.second >= 0 ){
            int mid_value = matrix[mid.first][mid.second];
            if(mid_value == target){
                return true;
            }else if(target < mid_value ){
                mid.second--;
            }else{
                mid.first++;
            }
        }
        return false;
    }
};
