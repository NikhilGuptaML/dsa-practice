/*
Problem: Single Element in a Sorted Array
LeetCode: 540
Difficulty: Medium
Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

---

Approach:
Every element in the sorted array appears twice except for one single element.
We can find the single element in O(log N) time using binary search.
The key observation is:
- To the left of the single element, the first occurrence of any pair starts at an even index, and the second occurrence is at an odd index (even, odd).
- To the right of the single element, the first occurrence starts at an odd index, and the second occurrence is at an even index (odd, even).
So, if `mid` satisfies the (even, odd) pairing configuration:
  - If `mid` is even and `nums[mid] == nums[mid + 1]` OR `mid` is odd and `nums[mid] == nums[mid - 1]`, we are on the left side of the single element. We search the right half by setting `st = mid + 1`.
  - Otherwise, we are on the right side of the single element. We search the left half by setting `end = mid - 1`.

Time Complexity:  O(log N) where N is the number of elements in `nums`.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- The array has only one element, handled by the initial `n == 1` check.
- The single element is at the very beginning or end of the array, handled by checking `nums[0] != nums[1]` and `nums[n - 1] != nums[n - 2]` beforehand.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
    
        if (nums[0] != nums[1]) return nums[0];
    
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int st  = 0;
        int end = n-1;
        while(st<=end){
            int mid = st + (end - st) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 != 0 && nums[mid] == nums[mid - 1])) {
                st = mid + 1; 
            } else {
                end = mid - 1; 
            }
        }
        return -1;
    }
};
