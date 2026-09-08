/*
Problem: Trapping Rain Water
LeetCode: 42
Difficulty: Hard
Link: https://leetcode.com/problems/trapping-rain-water/

---

Approach:
1. Solution 1 (Two Pointers): Uses a two-pointer technique (`l` starting from 0 and `r` starting from `N-1`) maintaining `lmax` and `rmax`. At each step, the smaller boundary determines the water level because the higher boundary on the opposite side guarantees that water up to `lmax` (or `rmax`) will be trapped.
2. Solution 2 (Prefix/Suffix Max Arrays): Precomputes two auxiliary arrays: `pref[i]` (maximum height from index 0 to `i`) and `suff[i]` (maximum height from index `i` to `N-1`). The water trapped above column `i` is `min(pref[i], suff[i]) - height[i]`.
3. Solution 3 (Monotonic Decreasing Stack): Maintains a stack of indices with decreasing heights. When `height[i] > height[st.top()]`, pops the bottom element (`top`). If stack is non-empty, calculates horizontal water bounds: `width = i - st.top() - 1` and `bounded_height = min(height[i], height[st.top()]) - height[top]`. Trapped water increment is `width * bounded_height`.

Time Complexity:  O(N) for all 3 solutions
Space Complexity: O(1) for Solution 1; O(N) for Solution 2 & Solution 3

---

Edge Cases:
- Array with fewer than 3 elements (e.g. [], [1], [1, 2]) where no water can be trapped.
- Monotonically increasing or decreasing heights (e.g. [1, 2, 3, 4] or [4, 3, 2, 1]) resulting in 0 trapped water.
- Flat elevation map (all equal values).
*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1: Two Pointers (O(1) Space)

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lmax = 0 , rmax = 0;
        int ans = 0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=lmax){
                    lmax = height[l];
                }else{
                    ans += lmax - height[l];
                }
                l++;
            }else{
                if(height[r]>=rmax){
                    rmax = height[r];
                }else{
                    ans += rmax - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};

// Solution 2: Prefix and Suffix Max Arrays (O(N) Space)

class SolutionPrefixSuffix {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = height[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], height[i]);
        }

        suff[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(pref[i], suff[i]) - height[i];
        }

        return ans;
    }
};

// Solution 3: Monotonic Decreasing Stack (O(N) Space)

class SolutionMonotonicStack {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; // No left boundary available

                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(i);
        }

        return ans;
    }
};
