/*
Problem: Merge Sorted Array
LeetCode: 88
Difficulty: Easy
Link: https://leetcode.com/problems/merge-sorted-array/

---

Approach:
We start merging the two sorted arrays from the back (rightmost elements) to avoid overwriting elements in `nums1`.
We maintain three pointers:
- `i` points to the last initialized element in `nums1` (`m - 1`).
- `j` points to the last element in `nums2` (`n - 1`).
- `k` points to the last index of the combined array `nums1` (`m + n - 1`).

We iterate from `k = m + n - 1` down to `0`:
- If `i == -1`, it means we have exhausted the elements of `nums1`. We copy the remaining elements of `nums2` into `nums1`.
- If `j == -1`, it means we have exhausted the elements of `nums2`. We copy the remaining elements of `nums1` (which are already in their correct places, but we copy them anyway).
- Otherwise, we compare `nums1[i]` and `nums2[j]`. We copy the larger value to `nums1[k]` and move the corresponding pointer (`i` or `j`) to the left.

Time Complexity:  O(m + n)
Space Complexity: O(1)

---

Edge Cases:
- `m = 0` (no elements in `nums1` to merge, only `nums2` has elements): We copy all elements of `nums2` directly to `nums1`.
- `n = 0` (no elements in `nums2` to merge): `nums1` is already in its final sorted state.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        for (; k > -1; k--) {
            if (i == -1) {
                nums1[k] = nums2[j];
                j--;
                continue;
            }
            if (j == -1) {
                nums1[k] = nums1[i];
                i--;
                continue;
            }
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
                continue;
            } else {
                nums1[k] = nums2[j];
                j--;
                continue;
            }
        }
    }
};
