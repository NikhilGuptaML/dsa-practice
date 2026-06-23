/*
Problem: 3Sum
LeetCode: 15
Difficulty: Medium
Link: https://leetcode.com/problems/3sum/

---

Approach:
Brute Force:
We use three nested loops to iterate through all possible triplets.
For each triplet, we check if their sum is equal to zero.
To handle duplicate triplets, we sort each valid triplet and insert it into a set.
Finally, we copy the elements from the set into a vector and return it.

Optimized:
We use a hash set to optimize the search for the third element.
For each element `nums[i]`, we iterate through the remaining elements `nums[j]`.
We search for the complement `-(nums[i] + nums[j])` in the hash set `seen` containing the elements visited in the inner loop.
If found, we sort the triplet and insert it into a set of unique triplets to avoid duplicates.

Most Optimal:
We first sort the array. Then, we fix one element `nums[i]` and use a two-pointer approach (`left` at `i + 1` and `right` at `size - 1`) to find other two elements.
To avoid duplicate triplets, we skip over identical elements for `i`, `left`, and `right` indices.
This eliminates the need for hash sets or duplicate sorting, achieving O(N^2) time complexity.

Time Complexity:  
- Brute Force: O(N^3 * log(number of unique triplets))
- Optimized: O(N^2 * log(number of unique triplets))
- Most Optimal: O(N^2)
Space Complexity: 
- Brute Force: O(number of unique triplets)
- Optimized: O(N + number of unique triplets)
- Most Optimal: O(1) auxiliary space

---

Edge Cases:
- The input array contains fewer than 3 elements, which is handled correctly by the loop bounds.
- All elements are 0, where duplicate skipping correctly outputs exactly one {0, 0, 0} triplet.
*/

// ── Brute Force ──────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> h;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {

                    if (nums[i] + nums[j] + nums[k] == 0) {

                        vector<int> ans = {nums[i], nums[j], nums[k]};
                        sort(ans.begin(), ans.end());

                        h.insert(ans);
                    }
                }
            }
        }

        return vector<vector<int>>(h.begin(), h.end());
    }
};

// ── Optimized ────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {

            unordered_set<int> seen;

            for (int j = i + 1; j < nums.size(); j++) {

                int target = -(nums[i] + nums[j]);

                if (seen.find(target) != seen.end()) {

                    vector<int> triplet = {
                        nums[i],
                        nums[j],
                        target
                    };

                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }

                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

// ── Most Optimal ─────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left, right;
        int size = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            left = i + 1;
            right = size - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
