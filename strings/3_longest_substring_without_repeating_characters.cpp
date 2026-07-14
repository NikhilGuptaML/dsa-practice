/*
# NOTE: Categorised under strings because the problem asks for the longest substring without repeating characters

Problem: Longest Substring Without Repeating Characters
LeetCode: 3
Difficulty: Medium
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

---

Approach:
We use a sliding window approach with two pointers (`left` and `right`) to find the longest substring without repeating characters.
As we expand the window by moving the `right` pointer, we keep track of the last seen index of each character in a hash map `r`.
If we encounter a character that is already present in `r`, we update the `left` pointer to be the maximum of its current position and `pt->second + 1` (one position after the last occurrence of the duplicate character).
This ensures that the window `[left, right]` always contains only unique characters.
At each step, we update the maximum length `ans = max(ans, right - left + 1)`.

Time Complexity:  O(N) (single pass of the string, with average O(1) hash map operations)
Space Complexity: O(min(M, N)) (where M is the size of the character set, e.g. 256 for ASCII, and N is the string length)

---

Edge Cases:
- Empty string input "", where the loop condition `right < s.size()` is never met, returning 0.
- String with all unique characters (e.g., "abcdef"), where `left` never updates, returning `s.size()`.
- String with all identical characters (e.g., "bbbbb"), where `left` moves forward with every step, returning 1.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> r;
        int left = 0;
        int right = 0;
        
        while (right < s.size()) {
            auto pt = r.find(s[right]);
            if (pt != r.end()) {
                left = max(left, pt->second + 1);
            }
            
            ans = max(ans, right - left + 1);
            
            r[s[right]] = right;
            right++;
        }
        return ans;
    }
};
