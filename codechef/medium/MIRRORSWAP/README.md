# MIRRORSWAP

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Mirror Swaps

You are given an array $A$ of $N$ integers. You can do the following operation as many times as you want:

- Choose an index $i$ ($1 \le i \le N$), and swap $A_i$ and $A_{N + 1 - i}$.

After your swaps, you want to maximize $\sum_{i = 1}^{N - 1} |A_i - A_{i + 1}|$. Find the maximum possible value, and the minimum number of swaps to achieve it.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains a single integer $N$. The second line contains $N$ integers - $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, output on a new line $2$ integers - the maximum value of $\sum_{i = 1}^{N - 1} |A_i - A_{i + 1}|$, and the minimum number of swaps to achieve it.

### Constraints
- $1 \le T \le 10^4$
- $2 \le N \le 2 \cdot 10^5$
- $1 \le A_i \le 10^9$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$
### Sample 1:
Input
Output

```
5
4
2 1 5 3
6
2 4 4 1 7 5
3
4 7 5
5
1 2 3 4 5
2
6 6

```

```
9 1
15 1
5 0
8 1
0 0
```

### Explanation:

 **Test Case 1:**  Do an operation with $i = 2$, and swap $A_2$ and $A_3$. Then, the array has the sum $|A_i - A_{i + 1}|$ equal to $|2 - 5| + |5 - 1| + |1 - 3| = 9$. This needed only one swap.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-11T16:01:42.966Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct State {
    ll score;
    int swaps;
};

// Custom comparator to maximize score, then minimize swaps
bool better(State a, State b) {
    if (a.score != b.score)
        return a.score > b.score;
    return a.swaps < b.swaps;
}

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int m = N / 2;
    State dp[2];

    // dp[0] = didn't swap the outermost pair
    // dp[1] = swapped the outermost pair
    dp[0] = {0, 0};
    dp[1] = {0, 1};

    for (int i = 1; i < m; i++) {
        State ndp[2];

        // c is the state of the CURRENT pair (i and N-1-i)
        for (int c = 0; c < 2; c++) {
            ndp[c] = {-1, INT_MAX};

            ll Lc = c ? A[N - 1 - i] : A[i];
            ll Rc = c ? A[i] : A[N - 1 - i];

            // p is the state of the PREVIOUS pair (i-1 and N-i)
            for (int p = 0; p < 2; p++) {
                ll Lp = p ? A[N - i] : A[i - 1];
                ll Rp = p ? A[i - 1] : A[N - i];

                State cur;
                cur.score = dp[p].score 
                            + abs(Lp - Lc) 
                            + abs(Rp - Rc);
                cur.swaps = dp[p].swaps + c;

                if (better(cur, ndp[c])) {
                    ndp[c] = cur;
                }
            }
        }
        dp[0] = ndp[0];
        dp[1] = ndp[1];
    }

    State ans = {-1, INT_MAX};

    // Tie up the middle elements
    for (int p = 0; p < 2; p++) {
        // FIXED: Using A[N-m] instead of A[0] connects the innermost elements
        ll L = p ? A[N - m] : A[m - 1];
        ll R = p ? A[m - 1] : A[N - m];

        State cur = dp[p];

        if (N % 2 == 1) {
            // Odd length: connect both innermost elements to the absolute middle
            ll mid = A[m];
            cur.score += abs(L - mid) + abs(R - mid);
        }
        else {
            // Even length: connect the two innermost elements directly together
            cur.score += abs(L - R);
        }

        if (better(cur, ans)) {
            ans = cur;
        }
    }

    cout << ans.score << " " << ans.swaps << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/MIRRORSWAP)