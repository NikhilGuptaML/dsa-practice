/*
Problem: Next Permutation
LeetCode: 31
Difficulty: Medium
Link: https://leetcode.com/problems/next-permutation/

---

Approach:
The solution finds the next lexicographically greater permutation by traversing from right to left to find the first element that is smaller than its successor (the pivot).
It then searches the suffix elements to the right of the pivot to find the smallest element that is strictly greater than the pivot, swaps them, and sorts the remaining suffix to ensure it is in ascending (lexicographical) order.
If no such pivot is found (meaning the array is sorted in descending order), it sorts the entire array to return the lowest possible lexicographical order.

Time Complexity:  O(n log n)
Space Complexity: O(1)

---

Edge Cases:
- Array is sorted in descending order (e.g., [3, 2, 1]): The pivot is never found, and the entire array is sorted to [1, 2, 3].
- Array is already sorted in ascending order (e.g., [1, 2, 3]): The pivot is the second-to-last element, swapped with the last element, and the last element is sorted.
- Array contains duplicate elements (e.g., [1, 1, 5] or [1, 5, 1]): The comparisons properly handle duplicate elements to find the next distinct permutation.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1;
        while(j>0){
            if(nums[j]>nums[j-1]){
                int min=j;
                for(int k = j;k<n;k++){
                    if(nums[k]>nums[j-1] && nums[k]<nums[min]){
                        min = k;
                    }
                }
                swap(nums[min],nums[j-1]);
                break;
            }j--;
        }
        sort(nums.begin() + j, nums.end());
        return;
    }
};
