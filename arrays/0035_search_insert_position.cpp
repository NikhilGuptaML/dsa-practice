/*
Problem: Search Insert Position
LeetCode: 35
Difficulty: Easy
Link: https://leetcode.com/problems/search-insert-position/

---

Approach:
We use a binary search approach to find the target value.
We maintain two pointers, `st` (start) and `end`.
In each step, we calculate `mid = st + (end - st) / 2`.
- If `nums[mid]` is equal to target, we return the index `mid`.
- If `target` is greater than `nums[mid]`, we search the right half by setting `st = mid + 1`.
- If `target` is smaller than `nums[mid]`, we search the left half by setting `end = mid - 1`.
If the target is not found in the array, the loop terminates when `st > end`. At this point, the pointer `st` points to the index where the target would be inserted to maintain sorted order, so we return `st`.

Time Complexity:  O(log N) where N is the number of elements in `nums`.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- The target is smaller than all elements in the array, in which case `end` keeps decreasing until it becomes -1, and we correctly return `st = 0`.
- The target is larger than all elements in the array, in which case `st` keeps increasing until it equals `nums.size()`, and we correctly return `st = nums.size()`.
- The array has only one element, handled correctly by the binary search range bounds.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return st;
    }
};
