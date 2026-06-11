/*
Problem: Majority Element
LeetCode: 169
Difficulty: Easy
Link: https://leetcode.com/problems/majority-element/

---

Approach:
We present two variations of the Boyer-Moore Majority Vote Algorithm:
1. Resetting on Negative Count: The initial solution initializes the candidate to the first element and resets the candidate only when the counter drops below zero (which is equivalent to a lazy candidate update).
2. Resetting on Zero Count (Optimal/Standard): The standard solution resets the candidate when the count reaches zero, immediately giving the new candidate a weight of 1. This is the canonical Boyer-Moore implementation.

Time Complexity:  O(n)
Space Complexity: O(1)

---

Edge Cases:
- Single element array (e.g., [1]): The algorithm immediately selects the element as the candidate and returns it.
- Alternating elements where the majority element is sparse at the beginning (e.g., [2, 1, 2, 1, 2]): The candidate switches back and forth but ends correctly on the majority element due to its net positive count.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

/*
// Initial Solution: Resetting on Negative Count
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0;
        int answer=nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==answer){
                n++;
            }else{
                n--;
            }
            if(n<0){
                answer=nums[i];n=0;
            }
        }
        return answer;
    }
};
*/

// Optimal Solution: Standard Boyer-Moore (Resetting on Zero Count)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0;
        int answer;
        for(int i = 0; i < nums.size(); i++){
            if(n==0){
                answer=nums[i];
            }
            if(nums[i]==answer){
                n++;
            }else{
                n--;
            }
            
        }
        return answer;
    }
};
