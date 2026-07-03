/*
Problem: Search in Rotated Sorted Array
LeetCode: 33
Difficulty: Medium
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

---

Approach:
We search for a target value in a rotated sorted array.
The algorithm divides the search space in half at each step. For any element at `mid`:
- If `nums[mid]` equals `target`, we return `mid`.
- If the right side `[mid, end]` is sorted (`nums[mid] < nums[end]`):
  - We run a binary search `bs` in the sorted right side `[mid, end]`.
  - If target is found there, we return its index.
  - Otherwise, we search the left side by updating `end = mid - 1`.
- If the left side `[st, mid]` is sorted (otherwise):
  - We run a binary search `bs` in the sorted left side `[st, mid]`.
  - If target is found there, we return its index.
  - Otherwise, we search the right side by updating `st = mid + 1`.
This reduces the search space logarithmically.

Time Complexity:  O(log N) where N is the number of elements in `nums`. In the worst case, we do binary search steps on subarray segments.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- The array is not rotated (fully sorted), which is handled correctly as the right side will continuously be recognized as sorted.
- The array contains only one element, where the search range terminates correctly.
- The target is not present in the array, returning `-1` as expected.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int bs(vector<int>& nums, int target, int st, int end) {

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        int ans;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < nums[end]) {
                ans = bs(nums, target, mid, end);
                if (ans != -1)
                    return ans;
                end = mid - 1;

            } else {
                ans = bs(nums, target, st, mid);
                if (ans != -1)
                    return ans;
                st = mid + 1;
            }
        }
        return -1;
    }
};
