// NOTE: Categorised under hashing because the most optimal solution uses a hash map (unordered_map) for O(1) lookup.
/*
Problem: Two Sum
LeetCode: 1
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum/

---

Approach:
Optimized (Two Pointers):
We store each element along with its original index as a pair in a vector, and then sort it.
We then use two pointers starting at both ends of the sorted array to find the two numbers that sum up to the target.
If the sum matches the target, we return their original indices. Otherwise, we adjust the pointers.

Most Optimal (Hashing):
We use a hash map to store each element and its corresponding index as we iterate through the array.
For each element, we check if its complement (target - current element) already exists in the map.
If it exists, we return the index of the complement and the current index.
Otherwise, we insert the current element and its index into the map.

Time Complexity:  
- Optimized: O(N log N)
- Most Optimal: O(N)
Space Complexity: 
- Optimized: O(N)
- Most Optimal: O(N)

---

Edge Cases:
- Duplicate values that sum up to the target (e.g. target is 6, nums is [3, 3]). In hashing, checking the map before insertion prevents matching an element with itself. In sorting, storing original indices allows distinct identification.
- Negative values in the array or target, which are handled correctly by lookups, sorting, and arithmetic.
*/

// ── Optimized (Two Pointers) ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> sorted_array;
        vector<int> ans;
        for(int i = 0; i< nums.size(); i++){
            sorted_array.push_back({nums[i], i});
        }
        sort(sorted_array.begin(), sorted_array.end());
        int i = 0; int j = nums.size()-1;int curSum;
        while(i<j){
            curSum = sorted_array[i].first+sorted_array[j].first;
            if(curSum==target){
                ans.push_back(sorted_array[i].second);
                ans.push_back(sorted_array[j].second);
                return ans;
            }
            else if(curSum>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};

// ── Most Optimal (Hashing) ────────────────────────────────────────────────────

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
