/*
Problem: 4Sum
LeetCode: 18
Difficulty: Medium
Link: https://leetcode.com/problems/4sum/

---

Approach:
We first sort the array. We use two nested loops to fix the first two elements `nums[i]` and `nums[j]`.
For each pair, we use a two-pointer approach with `l` (initialized to `j + 1`) and `r` (initialized to `size - 1`) to find the other two numbers.
We compute the sum of the four elements. To prevent integer overflow, we cast the addition to `long`.
If the sum is equal to the target, we record the quadruplet, move both pointers, and skip duplicates for `nums[l]`.
We also skip duplicates for `nums[i]` and `nums[j]` in the outer loops to avoid generating duplicate quadruplets.

Time Complexity:  O(N^3)
Space Complexity: O(1) auxiliary space

---

Edge Cases:
- The input array has fewer than 4 elements, which is handled correctly by the loop bounds.
- Integer overflow occurs when summing four elements; this is prevented by casting the sum computation to `long`.
- Consecutive duplicate elements are present in the sorted array, which are bypassed by the duplicate checks.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < size - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < size - 2; j++){
                if (j > i+1 && nums[j] == nums[j - 1])
                continue;
                int l = j+1;
                int r = size - 1;
                while(l<r){
                    long int sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum>target){
                        r--;
                    }else if(sum<target){
                        l++;
                    }else{
                        ans.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                        l++;r--;
                        while(l<r && nums[l]==nums[l-1]){
                            l++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
