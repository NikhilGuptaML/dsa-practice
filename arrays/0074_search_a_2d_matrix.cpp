/*
Problem: Search a 2D Matrix
LeetCode: 74
Difficulty: Medium
Link: https://leetcode.com/problems/search-a-2d-matrix/

---

Approach:
We present two solutions for this problem:
1. Virtual 1D Array Binary Search (Initial): Since the matrix is fully sorted, we treat it as a single, flat 1D array of size M * N and perform a single binary search. We map the mid index to 2D using matrix[mid / cols][mid % cols].
2. Double Binary Search (Optimal/Alternative): We perform two separate binary searches: first on the row start/end elements to find the potential row containing the target, and second on the columns of that row.

Time Complexity:  O(log(M * N)) (for both solutions)
Space Complexity: O(1)

---

Edge Cases:
- The matrix is 1x1. The search space consists of a single element, which is checked correctly by the binary search loops.
- The target is smaller than the minimum element (matrix[0][0]) or larger than the maximum element (matrix[M-1][N-1]). The binary search boundaries quickly move out of bounds, and the functions correctly return false.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

/*
// Solution 1: Virtual 1D Array Binary Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0;
        int cols =  matrix[0].size();
        int end = matrix.size() * cols - 1;
        int mid;
        while(st<=end){
            mid = st + (end - st)/2;
            int mid_val = matrix[mid / cols][mid % cols];
            
            if (mid_val == target) {
                return true;
            } 
            else if (mid_val < target) {
                st = mid + 1; 
            } 
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};
*/

// Solution 2: Double Binary Search (Row Selection + Column Search)
class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int rows = matrix.size();
        int cols = matrix[0].size();
        int st = 0;int end = cols - 1;

        while(st<=end){
            int mid = st + (end - st) / 2;
            if(matrix[row][mid]==target){
                return true;
            }else if( target > matrix[row][mid]){
                st = mid + 1;
            }else{
                end = mid -1;
            }
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int st = 0;int end = rows - 1;
        while(st<=end){
            int mid = st + (end - st) / 2;
            if(matrix[mid][0]<= target && matrix[mid][cols-1]>= target){
                return searchInRow( matrix,target,mid);
            }else if(target > matrix[mid][cols-1]){
                st = mid + 1;
            }else{
                end = mid -1;
            }
        }
        return false;
    }
};
