/*
Problem: Largest Odd Number in String
LeetCode: 1903
Difficulty: Easy
Link: https://leetcode.com/problems/largest-odd-number-in-string/

---

Approach:
To find the largest odd number substring, we search for the rightmost odd digit.
Since a number is odd if and only if its last digit is odd, the largest odd substring must be the longest prefix of `num` that ends with an odd digit.
We scan `num` from right to left (from the last character to the first) and find the first odd digit.
Once found, we return the substring from index 0 to that index.
If no odd digit is found, we return an empty string.

Time Complexity:  O(N)
Space Complexity: O(1) auxiliary space (O(N) to return the substring)

---

Edge Cases:
- String containing only even digits (e.g., "4206"), which returns "".
- String containing only odd digits (e.g., "357"), which returns "357".
- Odd digit at the start followed by even digits (e.g., "3542"), which correctly returns "35".
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        bool switch1 = false;
        for(int i = num.size()-1;i>=0;i--){
            if(switch1==true){
                ans+=num[i];
                continue;
            }
            if(int(num[i]) % 2!=0 && switch1==false){
                switch1 = true;
                ans+=num[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    string largestOddNumber(string num) {

        for (int i = num.size() - 1; i >= 0; i--) {

            if ((num[i] - '0') % 2 != 0) {

                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};
