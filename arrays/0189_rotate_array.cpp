/*
Problem: Rotate Array
LeetCode: 189
Difficulty: Medium
Link: https://leetcode.com/problems/rotate-array/

---

Approach:
We present two solutions for this problem to show the progression:
1. Auxiliary Array (Initial): We use a temporary array of the same size to store the rotated elements, copying them to `(i + k) % n`. Finally, we copy the temporary array back. This takes O(N) space.
2. In-place Reversal (Optimal): We rotate the array in-place by reversing the entire array, followed by reversing the first k elements, and then reversing the remaining n - k elements. This achieves O(1) space.

Time Complexity:  O(N) (for both solutions)
Space Complexity: O(1) (Optimal solution, O(N) for initial solution)

---

Edge Cases:
- k is equal to 0 or a multiple of the array length n, which is correctly handled by k % n.
- The array has only one element, in which case any rotation results in the same array.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

/*
// Initial Solution: O(N) Space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
    }
};
*/

// Optimal Solution: O(1) Space In-place
class Solution {
private:
    void reverse(vector<int>& nums, int st,int end){
        int temp;
        while(st<end){
            temp = nums[st];
            nums[st] = nums[end];
            nums[end] = temp;
            st++;
            end--;
        }
        return;
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
        return;
    }
};
