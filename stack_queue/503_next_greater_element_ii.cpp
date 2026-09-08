/*
Problem: Next Greater Element II
LeetCode: 503
Difficulty: Medium
Link: https://leetcode.com/problems/next-greater-element-ii/

---

Approach:
Simulates a circular array by performing two reverse passes over `nums` using a monotonic decreasing stack. The first pass populates standard next greater elements from right to left. The second pass processes the array right to left again using the existing stack state to resolve circular wrap-around next greater elements for remaining entries.

Time Complexity:  O(N) where N = nums.size()
Space Complexity: O(N) for output array and monotonic stack

---

Edge Cases:
- All elements equal (e.g. [1, 1, 1, 1]) -> output [-1, -1, -1, -1].
- Strictly decreasing array (e.g. [5, 4, 3, 2, 1]) -> wrap-around elements match highest element for all except maximum.
- Single element array.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
private:
stack<int> st;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i = nums.size()-1; i>=0;i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        for(int i = nums.size()-1; i>=0;i--){
            int temp = ans[i];
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                break;
            }else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
            
        }
        return ans;
    }
};
