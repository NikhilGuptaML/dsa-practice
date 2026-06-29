/*
Problem: Merge Intervals
LeetCode: 56
Difficulty: Medium
Link: https://leetcode.com/problems/merge-intervals/

---

Approach:
We first sort the intervals based on their start times. This guarantees that if two intervals overlap, they must be adjacent in the sorted array.
We initialize `si` (start index) and `ei` (end index) with the first interval's bounds.
Then, we iterate through the remaining intervals:
- If the current interval's start time is within the range `[si, ei]`, they overlap. We update `ei` to be the maximum of the current `ei` and the current interval's end time.
- If they do not overlap, we add the merged interval `[si, ei]` to our result and update `si` and `ei` to the current interval's bounds.
Finally, we push the last remaining interval `[si, ei]` to the result.

Time Complexity:  O(N log N) due to the sorting step, where N is the number of intervals.
Space Complexity: O(log N) or O(N) depending on the sorting implementation's auxiliary space.

---

Edge Cases:
- The input array contains only one interval, in which case the loop does not run, and the single interval is correctly pushed to the output.
- All intervals overlap, which is correctly merged into a single interval covering the entire range.
- No intervals overlap, where each interval is pushed individually without incorrect merging.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int si = nums[0][0];//starting index
        int ei = nums[0][1];//ending index
        for(int i = 1; i < nums.size();i++ ){
            if(nums[i][0]>=si && nums[i][0]<=ei){
                if(nums[i][1]>ei){
                    ei = nums[i][1];
                }
            }else{
                ans.push_back({si,ei});
                si = nums[i][0];
                ei = nums[i][1];
            }
        }
        ans.push_back({si,ei});
        return ans;
    }
};
