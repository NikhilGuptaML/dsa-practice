/*
Problem: Sort Colors
LeetCode: 75
Difficulty: Medium
Link: https://leetcode.com/problems/sort-colors/

---

Approach:
We use the Dutch National Flag algorithm to sort the array of 0s, 1s, and 2s in-place in a single pass.
We maintain three pointers:
- `i` represents the boundary of the 0s (elements before index `i` are 0).
- `j` represents the boundary of the 2s (elements after index `j` are 2).
- `k` is the current element pointer.
We iterate `k` from 0 to `j`:
- If `nums[k]` is 0, we swap `nums[k]` with `nums[i]`, increment `i`, and move `k` forward.
- If `nums[k]` is 2, we swap `nums[k]` with `nums[j]`, decrement `j`, and keep `k` at the current position (`k--` to counteract loop increment) to re-evaluate the swapped element.
- If `nums[k]` is 1, we simply increment `k`.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- The array contains only one element, in which case the loop condition `k <= j` immediately terminates or runs once without swapping, returning the correct array.
- The array contains only one color (e.g., all 0s, 1s, or 2s) or is already sorted, which is handled correctly by pointer swaps or passes without any incorrect modifications.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;int j = nums.size()-1;int pointer;
        for(int k = 0; k <= j;k++){
            if(nums[k]==0){
                swap(nums[k],nums[i]);
                i++;
                continue;
            }
            if(nums[k]==2){
                swap(nums[k],nums[j]);
                j--;k--;
                continue;
            }

        }
        return;
    }
};
