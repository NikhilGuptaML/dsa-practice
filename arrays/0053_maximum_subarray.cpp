/*
Problem: Maximum Subarray
LeetCode: 53
Difficulty: Medium
Link: https://leetcode.com/problems/maximum-subarray/

---

Approach:
The solution uses Kadane's Algorithm to find the maximum subarray sum in O(n) time and O(1) space.
We maintain two variables:
- `ans` (initialized to INT_MIN) to store the maximum subarray sum found so far.
- `temp` (initialized to 0) to store the running sum of the current subarray.
For each element, we add it to `temp`. If `temp` exceeds `ans`, we update `ans`. If `temp` becomes negative, it means extending the current subarray will only decrease the sum of any subsequent subarrays, so we discard it by resetting `temp` to 0.

Time Complexity:  O(n)
Space Complexity: O(1)

---

Edge Cases:
- All negative numbers (e.g., [-3, -1, -2]): The algorithm correctly returns the largest single negative element (in this case, -1) because we update `ans` before resetting `temp` to 0.
- Single element array (e.g., [1] or [-1]): The loop runs exactly once, updating `ans` to the value of that element.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = nums[i] + temp;
            if(temp>ans){
                ans = temp;
            }
            if(temp<0){
                temp =0;
            }
        }
        return ans;
    }
};
