// NOTE: Categorised under hashing because the solution uses a hash map (unordered_map) for O(1) lookup.
/*
Problem: Two Sum
LeetCode: 1
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum/

---

Approach:
We use a hash map to store the elements we have visited along with their indices.
For each element in the array, we check if its complement (target - current element) already exists in the hash map.
If it exists, we return the index of the complement and the current index.
Otherwise, we insert the current element and its index into the map.
This allows us to find the pair in a single pass.

Time Complexity:  O(N)
Space Complexity: O(N)

---

Edge Cases:
- The array contains duplicate values that could sum up to the target (e.g. target is 6, nums is [3, 3]). Checking the map before inserting ensures we don't match an element with itself, but we can match with a previously seen duplicate.
- The target or array values are negative, which is handled correctly by hash map lookups.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u;

        for (int i = 0; i < nums.size(); i++) {
            int tar = target - nums[i];

            auto it = u.find(tar);

            if (it != u.end()) {
                return {it->second, i};
            }

            u[nums[i]] = i;
        }

        return {-1, -1};
    }
};
