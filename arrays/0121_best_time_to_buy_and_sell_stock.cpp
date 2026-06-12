/*
Problem: Best Time to Buy and Sell Stock
LeetCode: 121
Difficulty: Easy
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

---

Approach:
We use a two-pointer sliding window approach to find the maximum profit. The pointer `i` tracks the day with the minimum buying price found so far, and the pointer `j` scans the subsequent days to find a selling price. If we encounter a price at `j` that is lower than the price at `i`, we update `i` to `j` because any future transaction would yield a higher profit starting from this new lower price. Otherwise, we calculate the profit of selling on day `j` and update the maximum profit if it exceeds the previous maximum.

Time Complexity:  O(n)
Space Complexity: O(1)

---

Edge Cases:
- Prices in strictly descending order (e.g., [7, 6, 4, 3, 1]): The algorithm updates the buy pointer `i` constantly, never finding a positive profit, and correctly returns 0.
- Single element array (e.g., [5]): The loop condition `j < prices.size()` (with `j = 1`) is false, so the loop does not run and the function correctly returns 0.
- The minimum price occurs on the last day (e.g., [3, 5, 1]): The buy pointer `i` moves to the last day, but since it is the last element, the loop ends immediately, preserving the correct maximum profit (2) from earlier days.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0 ; int j = 1; int profit=0;
        while(j<prices.size()){
            int temp = prices[j]-prices[i];
            if(prices[j]<prices[i]){
                i = j;
                j++;
                continue;
            }else{
                if(profit < temp){
                    profit = temp;  
                }
                j++;
            }
        }
        return profit;
    }
};
