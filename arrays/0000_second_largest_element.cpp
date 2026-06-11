/*
Problem: Second Largest Element
LeetCode: N/A
Difficulty: Easy

---

Approach:
We keep track of the largest and second largest values while traversing the array in a single pass.
If the current element is strictly greater than the largest, the current largest becomes the second largest, and largest is updated to the current element.
Otherwise, if the current element is strictly smaller than the largest but strictly greater than the second largest, we update the second largest.
This allows us to find the second largest element in linear time without sorting.

Time Complexity:  O(N)
Space Complexity: O(1)

---

Edge Cases:
- The input array is empty or contains only one element, so no second largest element can exist.
- All elements in the array are identical (e.g., [10, 10, 10]), meaning there is no unique second largest element.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.empty()){
            return -1;
        }
        if(nums.size()==1){
            return -1;
        }
        int largest = nums[0];
        int secondLargest = INT_MIN;
        for(int i =1; i<nums.size(); i++){
            if(nums[i]>largest){
                secondLargest = largest;
                largest = nums[i];
            }
            if(nums[i]< largest && nums[i]> secondLargest){
                secondLargest = nums[i];
            }
        }
        if(secondLargest==INT_MIN){
            return -1;
        }
        return secondLargest;
    }
};
