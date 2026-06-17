/*
Problem: Richest Customer Wealth
LeetCode: 1672
Difficulty: Easy
Link: https://leetcode.com/problems/richest-customer-wealth/

---

Approach:
We calculate the wealth of each customer by summing their bank account values (row sums in the accounts grid).
We iterate through each customer's account list, compute the total wealth for that customer, and update our running maximum wealth.
Since the constraints guarantee that the matrix is non-empty, we can safely access dimensions and initialize the maximum wealth to INT_MIN.

Time Complexity:  O(M * N) where M is the number of customers and N is the number of banks
Space Complexity: O(1)

---

Edge Cases:
- The grid has minimum dimensions of 1x1. The loops run exactly once, correctly returning the single account value as the max wealth.
- All customers have the exact same wealth. The maximum wealth variable correctly captures and returns this common wealth.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxSum = INT_MIN;
        for(int i = 0; i< accounts.size(); i++ ){
            int sum = 0;
            for(int j = 0; j< accounts[0].size(); j++){
                sum += accounts[i][j];
            }
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};
