/*
Problem: Merge Sort
LeetCode: N/A
Difficulty: Medium

---

Approach:
Divides the array into two halves recursively until single-element subarrays remain. Then merges two sorted subarrays back together in sorted order using an auxiliary vector before copying back into the original array range.

Time Complexity:  O(N log N)
Space Complexity: O(N) for temporary merge storage and recursion stack

---

Edge Cases:
- Single element or empty array input (handled by base case condition `st >= end`).
- Already sorted or reverse sorted arrays.
- Array with duplicate or all identical elements.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

#include <vector>

using namespace std;

class Solution {
private:
    void merge(vector<int> &nums, int st, int mid, int end) {
        int i = st;
        int j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int idx = 0; idx < temp.size(); idx++) {
            nums[st + idx] = temp[idx];
        }
    }

    void mergeSortHelper(vector<int> &nums, int st, int end) {
        if (st >= end) {
            return;
        }
        int mid = st + (end - st) / 2;

        mergeSortHelper(nums, st, mid);
        mergeSortHelper(nums, mid + 1, end);

        merge(nums, st, mid, end);
    }

public:
    void mergeSort(vector<int> &nums) {
        if (nums.empty()) return;
        mergeSortHelper(nums, 0, nums.size() - 1);
    }
};
