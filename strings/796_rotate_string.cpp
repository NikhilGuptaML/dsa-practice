/*
Problem: Rotate String
LeetCode: 796
Difficulty: Easy
Link: https://leetcode.com/problems/rotate-string/

---

Approach:
We first check if the lengths of string `s` and string `goal` are equal. If not, one cannot be a rotation of the other, so we return false.
If they are of the same length, we concatenate `s` with itself (`s + s`). This doubled string contains all possible cyclic rotations of `s` as substrings of length equal to `s.size()`.
We then check if `goal` is a substring of this doubled string using `find()`.

Time Complexity:  O(N) (under the assumption that string search runs in linear time)
Space Complexity: O(N) (to store the doubled string)

---

Edge Cases:
- Strings of different lengths (e.g. s = "abc", goal = "abcd"), which immediately returns false.
- Empty strings, which naturally returns true if both are empty.
- No rotation matches (e.g. s = "abc", goal = "cab" vs s = "abc", goal = "acb"), returning false.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) return false;
        

        string doubled = s + s;
        
        return doubled.find(goal) != string::npos;
    }
};
