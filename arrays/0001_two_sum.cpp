/*
Problem: Two Sum
LeetCode: 1
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum/

---

Approach:
We store each element along with its original index as a pair in a vector, and then sort it.
We then use two pointers, one starting at the beginning and the other at the end of the sorted array.
We compute the sum of the elements at the two pointers.
If the sum matches the target, we return the original indices.
If the sum is larger than the target, we move the right pointer leftward.
If the sum is smaller, we move the left pointer rightward.

Time Complexity:  O(N log N)
Space Complexity: O(N)

---

Edge Cases:
- Duplicate values that sum up to the target (e.g., target is 6, nums is [3, 3]). Since we store distinct indices for each value, the two-pointer approach correctly finds the distinct indices.
- Negative values in the array or target, which are handled correctly by sorting and addition.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

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
