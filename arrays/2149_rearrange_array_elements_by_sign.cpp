/*
Problem: Rearrange Array Elements by Sign
LeetCode: 2149
Difficulty: Medium
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

---

Approach:
We use a two-pointer approach to construct the rearranged array in a single pass. We initialize one pointer `j = 0` for placing positive numbers at even indices, and another pointer `k = 1` for placing negative numbers at odd indices. As we traverse the input array `nums`, we place positive numbers at index `j` and increment `j` by 2, and negative numbers at index `k` and increment `k` by 2. This satisfies the relative ordering requirement and ensures positive and negative numbers alternate.

Time Complexity:  O(n)
Space Complexity: O(n)

---

Edge Cases:
- Minimum size array (e.g., nums of size 2, like [-1, 1]): The algorithm handles it correctly, placing the positive integer at index 0 and the negative integer at index 1.
- Array elements already alternate in sign: The order is preserved correctly, and pointers are updated as expected.
- All positive numbers are clustered at the beginning/end: The relative order of positives and negatives is still preserved perfectly in the output array using their respective pointers.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int j=0;int k=1;
        vector<int> ans(nums.size());
       for(int i = 0;i< nums.size();i++){
            if(nums[i]>=0){
                ans[j]=nums[i];
                j+=2;
            }else{
                ans[k]=nums[i];
                k+=2;
            }
       }
       return ans;
    }
};
