/*
Problem: Subarray Sum Equals K
LeetCode: 560
Difficulty: Medium
Link: https://leetcode.com/problems/subarray-sum-equals-k/

---

Approach:
We use a prefix sum approach combined with a hash map to count the number of subarrays that sum to `k` in O(N) time.
First, we construct a prefix sum array `sumArr` where `sumArr[i]` stores the sum of elements from index 0 to `i`.
Then, we iterate through the prefix sums. For each prefix sum `sumArr[j]`, we want to find how many times a prefix sum equal to `sumArr[j] - k` has occurred previously.
Each such occurrence represents a valid subarray ending at `j` with sum equal to `k`.
We maintain a frequency map `m` of prefix sums seen so far to count these occurrences efficiently.

Time Complexity:  O(N) where N is the number of elements in `nums`. We traverse the array to compute prefix sums and then traverse again to find the count.
Space Complexity: O(N) auxiliary space for the prefix sum array and the hash map.

---

Edge Cases:
- The target `k` is negative, which is correctly handled by the hash map lookups of `sumArr[j] - k`.
- The array contains negative numbers, where prefix sums can decrease and increase, handled correctly by storing frequencies of all prefix sums in the map.
- Subarrays starting at index 0 sum to `k` (i.e. `sumArr[j] == k`), which is explicitly handled by the check `if(sumArr[j]==k) ans++`.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefix_sum approach

        vector<int> sumArr(nums.size());
        sumArr[0] = nums[0];
        int ans = 0;
        for(int i = 1; i < nums.size(); i++ ){
            sumArr[i] = sumArr[i-1]+nums[i];
        }
        unordered_map<int, int> m;
       
        for(int j = 0 ; j < nums.size() ; j ++ ){
            if(sumArr[j]==k) ans++;
            int tar = sumArr[j] - k;
            if(m.find(tar)!=m.end()){
                ans+=m.find(tar)->second;
            }
            m[sumArr[j]]++;
        }
        return ans;
    }
};
