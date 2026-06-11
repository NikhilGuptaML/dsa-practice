/*
Problem: Remove Duplicates from Sorted Array
LeetCode: 26
Difficulty: Easy
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

---

Approach:
We use a two-pointer approach to process the sorted array in-place.
One pointer tracks the index of the last written unique element, while a second pointer iterates through the array.
Whenever we encounter a new element that is different from the current unique element, we increment the write pointer and copy the new element to that position.
This allows us to shift all unique elements to the front of the array in a single pass.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- The input array has a length of 1, which has no duplicates, so the loop does not run and we correctly return 1.
- All elements in the array are identical, in which case the loop runs but never finds a different element, so we correctly return 1 without modifying the array.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pointer = 0;
        int currNum = nums[0];
        for(int i = 1 ; i < nums.size();i++){
            if(nums[i]!=currNum){
                pointer++; currNum = nums[i];
                nums[pointer]=currNum;
            }
            
        }
        return pointer + 1;
    }
};
