/*
Problem: Koko Eating Bananas
LeetCode: 875
Difficulty: Medium
Link: https://leetcode.com/problems/koko-eating-bananas/

---

Approach:
We want to find the minimum integer eating speed `k` such that Koko can eat all the bananas within `h` hours.
Since Koko can eat at a speed of at least 1 and at most the maximum number of bananas in any single pile (let's call it `max`), the range of possible speeds is `[1, max]`.
Because this range is sorted, we can binary search for the optimal speed `k`.
- For a candidate speed `mid`, we calculate the total hours Koko takes using the helper function `check`.
- If the total hours exceeds `h`, the speed `mid` is too slow, so we search the right half by setting `st = mid + 1`.
- Otherwise, Koko can finish all bananas at speed `mid` within `h` hours. We update our answer to be the minimum of `mid` and the current `ans`, and we try to find a slower speed by searching the left half (`end = mid - 1`).

Time Complexity:  O(N * log(max)) where N is the number of piles, and `max` is the maximum element in `piles`.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- `h` is equal to the number of piles, in which case Koko must eat at the maximum speed possible (which is `max`).
- The piles contain very small elements, handled correctly by the binary search range beginning at 1.
- Potential integer overflow during hours sum, handled by using `long long` for the sum in the `check` helper function.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    long long check(vector<int>& piles, int h,int k){
        long long int cur=0;
        for(int i = 0; i < piles.size();i++){
            cur += piles[i]/k;
            if(piles[i]%k!=0){
                cur++;
            } 
        }
        return cur;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *std::max_element(std::begin(piles), std::end(piles));
        int ans = max;

        int st = 1;
        int end = max;

        while(st<=end){
            int mid = st + (end - st) / 2;
            long long temp = check(piles,h,mid);
            if(temp>h){
                st = mid + 1;
            }else {
                ans = min(mid,ans);
                end = mid -1;
            }
        }
        return ans;
    }
};
