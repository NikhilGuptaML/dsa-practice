/*
Problem: Sum of Subarray Minimums
LeetCode: 907
Difficulty: Medium
Link: https://leetcode.com/problems/sum-of-subarray-minimums/

---

Approach:
Uses a monotonic increasing stack to find the contribution of each element as the minimum value across all subarrays containing it. For an element at `popped_idx`, the number of valid subarrays where it is the minimum is `lD * rD`, where `lD` is the distance to the previous smaller element on the left and `rD` is the distance to the next smaller (or equal) element on the right. The overall answer is updated modulo 10^9 + 7.

Time Complexity:  O(N) single-pass with stack flush where N = arr.size()
Space Complexity: O(N) auxiliary space for the monotonic stack

---

Edge Cases:
- Duplicate elements in `arr` (handled cleanly by strict `>` inequality to avoid double counting duplicate minimums across overlapping subarrays).
- Overflow during multiplication of `lD * rD * arr[popped_idx]` (prevented using `long long` and modulo arithmetic `% MOD`).
- Single-element array (returns `arr[0] % MOD`).
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        stack<int> st;
        long long ans = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){

            while(!st.empty() && arr[st.top()] > arr[i]){
                int popped_idx = st.top();
                st.pop();
                
                int lD = st.empty() ? (popped_idx + 1) : (popped_idx - st.top());
                int rD = i - popped_idx;

                ans = (ans + (long long)lD * rD * arr[popped_idx]) % MOD;
            }
            st.push(i);
        }
        
  
        while(!st.empty()){
            int popped_idx = st.top();
            st.pop();
            
            int lD = st.empty() ? (popped_idx + 1) : (popped_idx - st.top());
            int rD = n - popped_idx;

            ans = (ans + (long long)lD * rD * arr[popped_idx]) % MOD;
        }
        
        return ans;
    }
};
