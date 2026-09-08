/*
Problem: Online Stock Span
LeetCode: 901
Difficulty: Medium
Link: https://leetcode.com/problems/online-stock-span/

---

Approach:
1. Solution 1 (Brute Force Backward Scan): Stores all past prices in a vector and iterates backwards from the current element to count consecutive prior days with prices <= current price.
2. Solution 2 (Monotonic Index Stack): Uses a monotonic decreasing stack storing indices of historical prices. For each new price, it pops indices from the stack whose prices are <= current price. The span is `i - st.top()` (or `i + 1` if stack becomes empty).
3. Reference Solution (Monotonic Pair Stack): Stores `{price, span}` pairs directly on a monotonic stack. Avoids storing the entire price array. When popping elements with `price <= current price`, their accumulated spans are added directly to the current span (`span += st.top().second`).

Time Complexity:  O(N) per call for Solution 1; O(1) amortized per call for Solution 2 & Reference Solution
Space Complexity: O(N) to store historical prices and stack elements

---

Edge Cases:
- Monotonically increasing prices (e.g., 10, 20, 30, 40) causing stack to empty every time.
- Monotonically decreasing prices (e.g., 40, 30, 20, 10) where no elements are popped.
- Duplicate consecutive price values.
*/

// ── Solution ─────────────────────────────────────────────────────────────────

// Solution 1: Brute Force Backward Scan

class StockSpanner {
private:
vector<int> st;
int size;
public:
    StockSpanner() {
        size=-1;
    }
    
    int next(int price) {
        st.push_back(price);
        size++;
        int counter = 0;
        for(int i = size;i>=0;i--){
            if(st[i]>price){
                break;
            }
            counter++;
        }
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Solution 2: Monotonic Index Stack

class StockSpanner {

private:
    stack<int> st;
    vector<int> stock;
    int i;
    int ans;

public:
    StockSpanner() { i = -1; }

    int next(int price) {
        stock.push_back(price);
        i++;

        while (!st.empty() && stock[st.top()] <= price) {
            st.pop();
        }
        if (st.empty()) {
            st.push(i);
            return i + 1;
        }
        ans = i - st.top();
        st.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// ── Reference / Alternative Notes ─────────────────────────────────────────────

// Reference Solution: Monotonic Pair Stack ({price, span})
// Key Insight: Stores {price, span} pairs directly on the stack. When popping smaller/equal prices,
// their spans are accumulated into the current element's span (`span += st.top().second`).
// Eliminates the need to maintain an external history vector.

#include <stack>
#include <utility> // for std::pair

class StockSpannerReference {
public:
    // stack stores {price, span}
    std::stack<std::pair<int,int>> st;

    StockSpannerReference() {
        // nothing to initialize
    }
    
    int next(int price) {
        int span = 1;
        // Pop while previous prices are <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
