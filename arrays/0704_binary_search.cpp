/*
Problem: Binary Search
LeetCode: 704
Difficulty: Easy
Link: https://leetcode.com/problems/binary-search/

---

Approach:
We implement standard binary search on a sorted array of integers.
We maintain two pointers, `st` (start) and `end`.
In each step, we calculate the middle index `mid = st + (end - st) / 2` to avoid integer overflow.
- If `nums[mid]` is equal to target, we return `mid`.
- If `target` is greater than `nums[mid]`, the target must be in the right half, so we update `st = mid + 1`.
- If `target` is smaller than `nums[mid]`, the target must be in the left half, so we update `end = mid - 1`.
If `st` exceeds `end`, it means the target is not present in the array, so we return `-1`.

Time Complexity:  O(log N) where N is the number of elements in `nums`. In each step, we halve the search space.
Space Complexity: O(1) auxiliary space as the search is performed in-place.

---

Edge Cases:
- The array contains only one element, where the search range `st <= end` is evaluated once.
- The target is smaller than the smallest element or larger than the largest element, resulting in `st` exceeding `end` and returning `-1`.
- The target is present at the exact boundaries (first or last element), which is correctly found as the search space shrinks.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        while(st<=end){
            int mid = st + (end - st) / 2;
            if(target == nums[mid]){
                return mid;
            }else if(target > nums[mid]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
};
