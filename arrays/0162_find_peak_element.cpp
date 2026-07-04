/*
Problem: Find Peak Element
LeetCode: 162
Difficulty: Medium
Link: https://leetcode.com/problems/find-peak-element/

---

Approach:
A peak element is an element that is strictly greater than its neighbors.
We can find a peak element in logarithmic time using binary search.
- If the array has only 1 element, it is the peak, so we return index 0.
- If the first element is greater than the second, it is a peak (since nums[-1] is considered -∞), so we return 0.
- If the last element is greater than the second to last, it is a peak (since nums[n] is considered -∞), so we return n - 1.
Otherwise, the peak must lie within `[1, n - 2]`. We perform binary search in this range:
  - If `nums[mid]` is greater than both its neighbors, we found a peak and return `mid`.
  - If `nums[mid] < nums[mid + 1]`, we are on an upward slope, meaning a peak must exist to the right of `mid`, so we set `st = mid + 1`.
  - Otherwise, we are on a downward slope, meaning a peak must exist to the left of `mid`, so we set `end = mid - 1`.

Time Complexity:  O(log N) where N is the number of elements in `nums`. In each step, we reduce the search space by half.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- The array has only one element, handled by `n == 1` check.
- The peak is at the boundaries (first or last element), handled by the initial check.
- The array is strictly increasing or strictly decreasing, which resolves to the last or first element respectively.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();


        if (n == 1) return 0;


        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;


        int st = 1;
        int end = n - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            if (nums[mid] < nums[mid + 1]) {
                st = mid + 1;
            } 

            else {
                end = mid - 1;
            }
        }
        
        return -1; 
    }
};
