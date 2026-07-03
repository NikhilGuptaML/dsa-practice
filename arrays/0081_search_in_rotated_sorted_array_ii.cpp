/*
Problem: Search in Rotated Sorted Array II
LeetCode: 81
Difficulty: Medium
Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

---

Approach:
We search for a target value in a rotated sorted array that may contain duplicates.
Because of duplicate elements, we can encounter a state where the values at `st`, `mid`, and `end` are all equal (and not equal to the target).
In this case, we cannot determine which half of the array is sorted. To handle this, we shrink the search space from both ends (`st++` and `end--`) and continue.
Otherwise, we determine which half of the array is sorted:
- If the right side `[mid, end]` is sorted (`nums[mid] <= nums[end]`):
  - If the target lies within the range `(nums[mid], nums[end]]`, we perform a binary search `bs` in that right half.
  - Otherwise, we search the left half by setting `end = mid - 1`.
- If the left side `[st, mid]` is sorted (otherwise):
  - If the target lies within the range `[nums[st], nums[mid])`, we perform a binary search `bs` in that left half.
  - Otherwise, we search the right half by setting `st = mid + 1`.

Time Complexity:  O(N) in the worst case (when all or most elements are duplicates and we have to shrink the range one by one), but O(log N) on average.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- All elements in the array are duplicates (e.g. `[1, 1, 1, 1, 1]`) and target is not present, which is handled correctly by the `st++` and `end--` logic.
- The array has only one element, handled correctly by the `st <= end` condition.
- The target is present at the rotation point or boundaries.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    bool bs(vector<int>& nums, int target, int st, int end) {

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == nums[mid]) {
                return true;
            } else if (target > nums[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int st = 0; int end = nums.size()-1;
        while(st<=end){
            int mid = st + (end - st) / 2;
            if(nums[st]==nums[end] && nums[mid]==nums[st] && nums[mid]!= target){
                st++;end--;continue;
            }
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]<=nums[end]){
                if(nums[end]>=target && target>nums[mid]){
                    return bs(nums,target,mid+1,end);
                }else{
                    end = mid - 1;
                }
            }else{
                if(nums[st]<=target && target<nums[mid]){
                    return bs(nums,target,st,mid-1);
                }else{
                    st = mid + 1;
                }
            }
        }
        return false;
    }
};
