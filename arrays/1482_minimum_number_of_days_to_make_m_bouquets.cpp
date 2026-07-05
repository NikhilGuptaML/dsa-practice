/*
Problem: Minimum Number of Days to Make m Bouquets
LeetCode: 1482
Difficulty: Medium
Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

---

Approach:
We want to find the minimum day such that we can make `m` bouquets of `k` adjacent flowers.
Since the search space for the number of days ranges from the minimum element to the maximum element in `bloomDay`, and this range is sorted, we can perform binary search:
- For a candidate number of days `mid`, we iterate through the `bloomDay` array to count how many bouquets we can form.
- If we find a flower with `bloomDay[i] <= mid`, we increment our adjacent flower counter `tempCounter`. When `tempCounter` reaches `k`, we successfully form a bouquet, increment our bouquet counter `boq`, and reset `tempCounter` to 0.
- If `bloomDay[i] > mid`, we reset `tempCounter` to 0 since the flowers must be adjacent.
- If the total bouquets formed `boq` is greater than or equal to `m`, the day `mid` is possible. We save it as `minDay` and try to find a smaller number of days by searching the left half (`end = mid - 1`).
- Otherwise, `mid` days is not enough, so we search the right half by setting `st = mid + 1`.

Time Complexity:  O(N * log(max_day - min_day)) where N is the number of elements in `bloomDay`, and `max_day`/`min_day` are the maximum/minimum elements in the array.
Space Complexity: O(1) auxiliary space.

---

Edge Cases:
- The total flowers required (`m * k`) exceeds the total flowers available in `bloomDay`, in which case the binary search range terminates and we correctly return `-1`.
- `k = 1` (each bouquet is of size 1), where the check logic simplifies to counting elements <= `mid`.
- `m = 1` (need only one bouquet), handled correctly by the binary search range and counting logic.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // m is the no of boq
        // k is the adjacent flowers
        auto result =
            std::minmax_element(std::begin(bloomDay), std::end(bloomDay));
        int st = *result.first;
        int end = *result.second;
        int minDay = -1;
        while(st<=end){
            int mid = st + (end - st) / 2;
            int tempCounter = 0;
            int boq = 0;
            for(int i = 0; i <bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    tempCounter++;
                }else{
                    tempCounter=0;
                }
                if(tempCounter == k ){
                    boq++;
                    tempCounter=0;
                }
            }
            
            if(boq>=m){
                minDay = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return minDay;
    }
};
