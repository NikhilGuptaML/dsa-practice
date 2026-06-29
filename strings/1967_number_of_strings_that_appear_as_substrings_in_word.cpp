/*
Problem: Number of Strings That Appear as Substrings in Word
LeetCode: 1967
Difficulty: Easy
Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

---

Approach:
We iterate through each pattern string in `patterns` and check if it exists as a substring in `word`.
Using C++'s standard library function `word.find(ch)`, we search for the pattern.
If `word.find(ch)` does not return `std::string::npos`, it means the pattern exists in `word` as a substring, so we increment our counter.

Time Complexity:  O(N * M) where N is the number of patterns and M is the length of `word`. In the worst case, string search takes linear/quadratic time depending on the search algorithm.
Space Complexity: O(1) auxiliary space as we only use a counter.

---

Edge Cases:
- A pattern is identical to the `word` itself, which is correctly matched.
- No patterns are substrings of `word`, which returns 0.
- Multiple duplicate patterns exist in `patterns`, which are each checked and counted individually.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto ch: patterns){
            if(word.find(ch) != std::string::npos) ans++;
        }
        return ans;
    }
};
