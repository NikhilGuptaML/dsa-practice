/*
Problem: Number of Substrings Containing All Three Characters
LeetCode: 1358
Difficulty: Medium
Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

---

Approach:
We use a sliding window (two-pointer) approach to find all substrings containing at least one occurrence of 'a', 'b', and 'c'.
We maintain a frequency array/vector `store` of size 3 to keep track of the counts of 'a', 'b', and 'c' within the current window `[j, i]`.
As we expand the window by moving the right pointer `i` from 0 to `s.size() - 1`:
- We add the character `s[i]` to our window.
- While the window contains all three characters (i.e., `store[0] > 0 && store[1] > 0 && store[2] > 0`):
  - Any substring starting at index `j` and ending at index `i` or any index after `i` up to `n - 1` will also contain all three characters.
  - Thus, we add `n - i` to our answer.
  - We then shrink the window from the left by removing `s[j]` and incrementing `j`.

Time Complexity:  O(N) where N is the length of string `s`. Each character is visited at most twice (once by the right pointer `i` and once by the left pointer `j`).
Space Complexity: O(1) auxiliary space since the frequency array has a constant size of 3.

---

Edge Cases:
- The string `s` has length less than 3, where the loop runs but the inner `while` condition is never met, returning 0.
- The string contains only 'a', 'b', or 'c' (missing some characters), which correctly returns 0.
- The entire string contains all three characters, where we correctly identify and count all valid substrings.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> store(3,0);
        int n = s.size();
        int j = 0;
        for(int i = 0;i<s.size();i++){
            store[s[i] - 'a']++; 
            while (store[0] > 0 && store[1] > 0 && store[2] > 0) {
                ans += n - i;
                store[s[j] - 'a']--;
                j++;
            }
        }
        return ans;
    }
};
