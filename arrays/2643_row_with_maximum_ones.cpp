/*
Problem: Row With Maximum Ones
LeetCode: 2643
Difficulty: Easy
Link: https://leetcode.com/problems/row-with-maximum-ones/

---

Approach:
We traverse the binary matrix row by row. For each row, we sum the elements to count the number of ones.
We maintain the maximum count of ones (`maxSum`) and the corresponding row index (`index`).
By using a strict comparison (`sum > maxSum`) and traversing the rows from first to last, we automatically select the smallest row index in the case of a tie.

Time Complexity:  O(M * N) where M is the number of rows and N is the number of columns
Space Complexity: O(1)

---

Edge Cases:
- All rows have zero ones. The strict comparison ensures that the first row (index 0) is returned, which correctly has the smallest index.
- The matrix is 1x1. The loop runs once, initializing and correctly returning index 0 with its sum.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxSum = INT_MIN;
        int index;
        for(int i = 0; i< mat.size(); i++ ){
            int sum = 0;
            for(int j = 0; j< mat[0].size(); j++){
                sum += mat[i][j];
            }
            if(sum>maxSum){
                maxSum = sum;
                index = i;
            }
        }
        return {index , maxSum};
    }
};
