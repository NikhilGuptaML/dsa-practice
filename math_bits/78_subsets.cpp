/*
Problem: Subsets
LeetCode: 78
Difficulty: Medium
Link: https://leetcode.com/problems/subsets/

---

Approach:
Uses bit manipulation (bitmasking) to generate all 2^N subsets of a set of size N. Iterates an integer `num` from 0 to 2^N - 1, where the i-th bit of `num` indicates whether `nums[i]` should be included in the subset.

Time Complexity:  O(N * 2^N)
Space Complexity: O(1) auxiliary space (excluding output space O(N * 2^N))

---

Edge Cases:
- Empty input vector: Returns [[]].
- Single-element vector: Generates 2^1 = 2 subsets correctly.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n;
        vector<vector<int>> ans;
        for (int num = 0; num < totalSubsets; num++) {
            vector<int> currentList;
            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    currentList.push_back(nums[i]);
                }
            }
            ans.push_back(currentList);
        }
        return ans;
    }
};
