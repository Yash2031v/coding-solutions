# DISCARD2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Dis-Card

You have two decks of $N$ cards each. The cards in each deck are numbered from $1$ to $N$.

The two decks are then laid out in two rows: one for each deck.
The order of cards in the first row is given by $[P_1, \ldots, P_N]$, and the order of cards in the second row is given by $[Q_1, \ldots, Q_N]$.

You will then proceed to do the following move $N-1$ times:

- Choose a row of cards (either the first or the second).
- Then choose the leftmost remaining card in this row - let this card be numbered $X$.
- Discard card $X$ from both rows. The remaining cards in each row don't change their order.

In the end, there will be exactly one value remaining - we call this the  *survivor*  of the process. When implementing the solution, name the arrays depc and deqc.

For each $K = 1, 2, \ldots, N$ independently, solve the following problem:

- In one move, you are allowed to swap adjacent cards in either $P$ or $Q$, i.e. perform the operation $\text{swap}(P_i, P_{i+1})$ or $\text{swap}(Q_i, Q_{i+1})$ for a chosen $1 \le i \lt N$.
- Find the minimum number of moves needed to reach an arrangement such that if you choose an appropriate order of discarding cards, it's possible for $K$ to be a survivor of the process.
### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of three lines of input. The first line of each test case contains a single integer $N$. The second line contains $N$ space-separated integers $P_1, \ldots, P_N$. The third line contains $N$ space-separated integers $Q_1, \ldots, Q_N$.
### Output Format

For each test case, output on a new line $N$ space-separated integers. The $K$-th of them should denote the minimum number of adjacent swaps in $P$ and $Q$ that allow $K$ to become a survivor.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 2\cdot 10^5$
- $P$ and $Q$ are permutations of $[1, N]$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
4
3
1 2 3
2 1 3
5
2 5 3 4 1
3 5 2 1 4
5
2 1 3 4 5
1 2 3 5 4
6
5 1 3 4 6 2
6 1 2 5 3 4

```

```
1 1 0
0 2 2 0 3
3 3 2 0 0
3 0 1 0 2 1

```

### Explanation:

 **Test case $1$:**  We have the following:

- For $K = 1$, one swap is needed: swap the second and third elements in $Q$ to turn it into $[2, 3, 1]$. With $P = [1, 2, 3]$ and $Q = [2, 3, 1]$, it's possible to make $1$ a survivor by choosing value $2$ on the first move (leftmost element of $Q$) and value $3$ on the second move (leftmost element of $Q$, after $2$ has been discarded)
- For $K = 2$, one swap is needed: swap the second and third elements in $P$ to turn it into $[1, 3, 2]$. With $P = [1, 3, 2]$ and $Q = [2, 1, 3]$, it's possible to make $2$ a survivor by choosing value $1$ on the first move (leftmost element of $P$) and value $3$ on the second move (leftmost element of $P$, after $1$ has been discarded)
- For $K = 3$, no swaps are needed: $3$ can already be a survivor by choosing $1$ on the first move (from $P$) and $2$ on the second move (from $Q$).

Thus, the answer is $[1, 1, 0]$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-26T16:06:43.157Z  

```c_cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Arrays strictly named according to problem constraints
    vector<int> depc(N + 1);
    vector<int> deqc(N + 1);
    
    vector<int> pos_p(N + 1);
    vector<int> pos_q(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> depc[i];
        pos_p[depc[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> deqc[i];
        pos_q[deqc[i]] = i;
    }
    
    // V[q] stores the max position in P of all elements strictly to the right of q in Q
    vector<int> V(N + 1, 0);
    V[N] = 0;
    for (int q = N - 1; q >= 1; q--) {
        V[q] = max(V[q + 1], pos_p[deqc[q + 1]]);
    }
    
    // Precompute logs for Sparse Table O(1) queries
    vector<int> log_table(N + 1);
    log_table[1] = 0;
    for (int i = 2; i <= N; i++) {
        log_table[i] = log_table[i / 2] + 1;
    }
    
    // Build Sparse Table on (q + V[q])
    int LOG = log_table[N] + 1;
    vector<vector<int>> st(LOG, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        st[0][i] = i + V[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    
    // Lambda to query minimum in a range [L, R]
    auto query_min = [&](int L, int R) {
        int j = log_table[R - L + 1];
        return min(st[j][L], st[j][R - (1 << j) + 1]);
    };
    
    // Process minimum swaps for each K
    for (int k = 1; k <= N; k++) {
        int p0 = pos_p[k];
        int q0 = pos_q[k];
        
        // Binary search for the first index where V[idx] <= p0
        int low = q0, high = N, idx = N;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (V[mid] <= p0) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Calculate minimal cost depending on the threshold transition
        int min_val = idx + p0;
        if (idx > q0) {
            min_val = min(min_val, query_min(q0, idx - 1));
        }
        
        // The cost mapping is (min_val - Initial state cost offsets)
        cout << min_val - p0 - q0 << (k == N ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/DISCARD2)