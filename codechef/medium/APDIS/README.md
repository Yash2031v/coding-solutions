# APDIS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Progressive Purge

 *This is the easy version of the problem. The two versions differ only in the constraints on $N$. Here, $N \le 4000$ and $\sum N^2 \le 4000^2$ across all tests.* 

An array $B$ of length $M$ is called  *good*  if there exists a pair of integers $(i, d)$ satisfying the following conditions:

- $d \ge 2$, and
- Delete every element $B_j$ at an index $j$ such that $j \equiv i \pmod d$. Then, the resulting sequence is sorted in non-decreasing order.

You are given an array $A$. Count the number of its contiguous subarrays that are  *good*.

That is, count the number of pairs $(L, R)$ such that $1 \le L \le R \le N$ and the array
$[A_L, \ldots, A_R]$ is  *good*.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$. The second line contains $N$ space-separated integers $A_1, \ldots, A_N$.
### Output Format

For each test case, output on a new line the number of good subarrays of $A$.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 4000$
- $1 \le A_i \le N$
- The sum of $N^2$ over all test cases won't exceed $4000^2$.
### Sample 1:
Input
Output

```
6
2
2 1
1
1
4
2 2 1 1
5
3 4 2 1 1
7
3 7 1 5 2 6 4
10
7 2 9 1 5 7 3 8 2 6

```

```
3
1
9
12
24
38

```

### Explanation:

 **Test case $1$:**  There are three subarrays. The singletons are good because they're already sorted, and $[2, 1]$ is good because you can choose for example $(1, 3)$ to delete the first element, leaving a sorted array.

 **Test case $2$:**  There's only one subarray and it's sorted.

 **Test case $3$:**  There are $10$ subarrays. Among them, only $[2, 2, 1, 1]$ is not good - it can be verified that it's impossible to make it sorted by deleting elements at an arithmetic progression of indices.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-26T16:07:01.162Z  

```c_cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// Represent range [L, R] constraint updates
struct Update {
    int L, R;
};

const int MAXN = 4005;
vector<Update> updates1[MAXN];
vector<Update> updates2[MAXN];

// Fast disjoint-set union for offline range processing
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 2);
        for(int i = 0; i <= n + 1; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
};

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Trivial single-element edge case
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }

    for(int i = 0; i <= N; ++i) {
        updates1[i].clear();
        updates2[i].clear();
    }
    
    // Precalculate local 'removability' criteria
    vector<bool> valid(N + 2, false);
    valid[1] = true;
    valid[N] = true;
    for(int x = 2; x <= N - 1; ++x) {
        valid[x] = (A[x-1] <= A[x+1]);
    }
    
    vector<int> next_D(N + 2, N);
    int cur = N;
    for(int i = N; i >= 1; --i) {
        if (i < N && A[i] > A[i+1]) cur = i;
        next_D[i] = cur;
    }
    
    vector<int> prev_D(N + 2, 0);
    cur = 0;
    for(int i = 1; i <= N; ++i) {
        prev_D[i] = cur;
        if (i < N && A[i] > A[i+1]) cur = i;
    }
    
    // Process every global AP progression mathematically
    for(int d = 2; d <= N; ++d) {
        for(int i = 0; i < d; ++i) {
            
            // Gather Type A Constraints (Non-Removables)
            vector<int> A_pts;
            for(int k = 0; k <= N/d + 1; ++k) {
                int x = i + k * d;
                if (x >= 1 && x <= N) {
                    if (!valid[x]) A_pts.push_back(x);
                }
            }
            if (A_pts.empty() || A_pts.back() < N) {
                A_pts.push_back(N);
            }
            
            struct IntervalA { int L, R, val; };
            vector<IntervalA> A_intervals;
            int prev_A = 0;
            for (int a : A_pts) {
                if (prev_A <= a - 1) {
                    A_intervals.push_back({prev_A, a - 1, a});
                }
                prev_A = a;
            }
            if (prev_A <= N) A_intervals.push_back({prev_A, N, N});
            
            // Gather Type B Constraints (Uncovered Descents)
            vector<int> C;
            for(int k = 0; k <= N/d + 1; ++k) {
                int x1 = i - 1 + k * d;
                int x2 = i + k * d;
                if (x1 >= 1 && x1 <= N - 1 && A[x1] > A[x1+1]) C.push_back(x1);
                if (x2 >= 1 && x2 <= N - 1 && A[x2] > A[x2+1] && x2 != x1) C.push_back(x2);
            }
            
            // Generate Contiguous Block Exclusions limits via Next Descents 
            vector<pair<int, int>> blocks;
            if (!C.empty()) {
                int first = C[0], last = C[0];
                for(int j = 1; j < (int)C.size(); ++j) {
                    if (next_D[last + 1] == C[j]) {
                        last = C[j];
                    } else {
                        blocks.push_back({first, last});
                        first = C[j];
                        last = C[j];
                    }
                }
                blocks.push_back({first, last});
            }
            
            struct IntervalB { int L, R, val; };
            vector<IntervalB> B_intervals;
            int current_L = 1;
            for (auto& blk : blocks) {
                int first = blk.first, last = blk.second;
                int p_D = prev_D[first];
                int L_start = p_D + 1;
                int L_end = last;
                
                if (current_L < L_start) B_intervals.push_back({current_L, L_start - 1, -1});
                
                if (L_start <= L_end) {
                    int b_val = next_D[last + 1];
                    B_intervals.push_back({max(current_L, L_start), L_end, b_val});
                }
                current_L = max(current_L, L_end + 1);
            }
            if (current_L <= N) B_intervals.push_back({current_L, N, -1});
            
            // Two-pointer Interval Intersection for piece-wise alignments
            int i_A = 0, i_B = 0;
            while(i_A < A_intervals.size() && i_B < B_intervals.size()) {
                int A_L = A_intervals[i_A].L, A_R = A_intervals[i_A].R, a_val = A_intervals[i_A].val;
                int B_L = B_intervals[i_B].L, B_R = B_intervals[i_B].R, b_val = B_intervals[i_B].val;
                
                int intersect_L = max({A_L, B_L, 1});
                int intersect_R = min(A_R, B_R);
                
                if (intersect_L <= intersect_R) {
                    if (b_val != -1) {
                        int final_val = min(a_val, b_val);
                        updates1[final_val].push_back({intersect_L, intersect_R});
                    } else {
                        int final_val = a_val;
                        updates2[final_val].push_back({intersect_L, intersect_R});
                    }
                }
                
                if (A_R < B_R) i_A++;
                else i_B++;
            }
        }
    }
    
    // Evaluate maximum extent using Bucketing and DSU paths resolving overall O(N log* N)
    vector<int> max_X1(N + 1, 0);
    DSU dsu1(N);
    for(int X = N; X >= 1; --X) {
        for(auto& p : updates1[X]) {
            int L = p.L, R = p.R;
            int curr = dsu1.find(L);
            while(curr <= R) {
                max_X1[curr] = X;
                dsu1.parent[curr] = curr + 1;
                curr = dsu1.find(curr);
            }
        }
    }
    
    vector<int> max_X2(N + 1, 0);
    DSU dsu2(N);
    for(int X = N; X >= 1; --X) {
        for(auto& p : updates2[X]) {
            int L = p.L, R = p.R;
            int curr = dsu2.find(L);
            while(curr <= R) {
                max_X2[curr] = X;
                dsu2.parent[curr] = curr + 1;
                curr = dsu2.find(curr);
            }
        }
    }
    
    long long ans = 0;
    for(int L = 1; L <= N; ++L) {
        int r = next_D[L];
        r = max(r, max_X1[L]);
        r = max(r, min(max_X2[L], next_D[L]));
        r = min(r, N);
        ans += (r - L + 1);
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/APDIS)