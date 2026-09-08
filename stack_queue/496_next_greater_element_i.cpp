/*
Problem: Next Greater Element I
LeetCode: 496
Difficulty: Easy
Link: https://leetcode.com/problems/next-greater-element-i/

---

Approach:
Traverses `nums2` from right to left using a monotonic decreasing stack to precompute the next greater element for every value in `nums2`. Results are mapped in a hash table `temp` where `temp[val]` holds the next greater element (or -1 if none exists). Finally, `nums1` elements are mapped to their precomputed answers in O(1) time each.

Time Complexity:  O(N1 + N2) where N1 = nums1.size() and N2 = nums2.size()
Space Complexity: O(N2) for the hash map and monotonic stack

---

Edge Cases:
- No next greater element exists for an element (stores -1).
- Single-element vectors or strictly decreasing arrays (where all elements get -1).
- `nums1` is a subset of `nums2` (as per problem constraints).
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
private:
    stack<int> st;
    unordered_map<int, int> temp;
    

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                temp[nums2[i]] = -1;
            } else {
                temp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int i = nums1.size() - 1; i >= 0; i--) {
            ans[i] = temp[nums1[i]];
        }
        return ans;
    }
};
