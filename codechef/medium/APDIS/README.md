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
**Submitted:** 2026-08-26T16:08:57.164Z  

```c_cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4005;

struct Update {
    int L, R;
};

struct IntervalA { int L, R, val; };
struct IntervalB { int L, R, val; };

// Pre-allocate global arrays to avoid ANY dynamic memory allocation in the hot loops
vector<Update> updates1[MAXN];
vector<Update> updates2[MAXN];
int A[MAXN], next_D[MAXN], prev_D[MAXN];
bool valid[MAXN];

int A_pts[MAXN];
int C_pts[MAXN];
pair<int, int> blocks[MAXN];
IntervalA A_intervals[MAXN];
IntervalB B_intervals[MAXN];

int dsu1_parent[MAXN];
int dsu2_parent[MAXN];
int max_X1[MAXN];
int max_X2[MAXN];

int find_dsu(int* parent, int i) {
    int root = i;
    while (root != parent[root]) root = parent[root];
    int curr = i;
    while (curr != root) {
        int nxt = parent[curr];
        parent[curr] = root;
        curr = nxt;
    }
    return root;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }

    for(int i = 0; i <= N; ++i) {
        updates1[i].clear();
        updates2[i].clear();
        max_X1[i] = 0;
        max_X2[i] = 0;
        dsu1_parent[i] = i;
        dsu2_parent[i] = i;
    }
    dsu1_parent[N + 1] = N + 1;
    dsu2_parent[N + 1] = N + 1;
    
    valid[1] = true;
    valid[N] = true;
    for(int x = 2; x <= N - 1; ++x) {
        valid[x] = (A[x-1] <= A[x+1]);
    }
    
    int cur = N;
    for(int i = N; i >= 1; --i) {
        if (i < N && A[i] > A[i+1]) cur = i;
        next_D[i] = cur;
    }
    
    cur = 0;
    for(int i = 1; i <= N; ++i) {
        prev_D[i] = cur;
        if (i < N && A[i] > A[i+1]) cur = i;
    }
    
    // Core logic: Heavy operations replaced with lightweight pointer arithmetic
    for(int d = 2; d <= N; ++d) {
        for(int i = 0; i < d; ++i) {
            
            // 1. Gather Type A Constraints
            int a_sz = 0;
            for(int k = 0; k <= N/d + 1; ++k) {
                int x = i + k * d;
                if (x >= 1 && x <= N && !valid[x]) {
                    A_pts[a_sz++] = x;
                }
            }
            if (a_sz == 0 || A_pts[a_sz - 1] < N) {
                A_pts[a_sz++] = N;
            }
            
            int intA_sz = 0;
            int prev_A = 0;
            for (int idx = 0; idx < a_sz; ++idx) {
                int a = A_pts[idx];
                if (prev_A <= a - 1) A_intervals[intA_sz++] = {prev_A, a - 1, a};
                prev_A = a;
            }
            if (prev_A <= N) A_intervals[intA_sz++] = {prev_A, N, N};
            
            // 2. Gather Type B Constraints
            int c_sz = 0;
            for(int k = 0; k <= N/d + 1; ++k) {
                int x1 = i - 1 + k * d;
                int x2 = i + k * d;
                if (x1 >= 1 && x1 < N && A[x1] > A[x1+1]) C_pts[c_sz++] = x1;
                if (x2 >= 1 && x2 < N && A[x2] > A[x2+1] && x2 != x1) C_pts[c_sz++] = x2;
            }
            
            int b_sz = 0;
            if (c_sz > 0) {
                int first = C_pts[0], last = C_pts[0];
                for(int j = 1; j < c_sz; ++j) {
                    if (next_D[last + 1] == C_pts[j]) {
                        last = C_pts[j];
                    } else {
                        blocks[b_sz++] = {first, last};
                        first = C_pts[j];
                        last = C_pts[j];
                    }
                }
                blocks[b_sz++] = {first, last};
            }
            
            int intB_sz = 0;
            int current_L = 1;
            for (int idx = 0; idx < b_sz; ++idx) {
                int first = blocks[idx].first, last = blocks[idx].second;
                int L_start = prev_D[first] + 1;
                
                if (current_L < L_start) {
                    B_intervals[intB_sz++] = {current_L, L_start - 1, -1};
                }
                if (L_start <= last) {
                    B_intervals[intB_sz++] = {max(current_L, L_start), last, next_D[last + 1]};
                }
                current_L = max(current_L, last + 1);
            }
            if (current_L <= N) B_intervals[intB_sz++] = {current_L, N, -1};
            
            // 3. Interval Intersection logic
            int i_A = 0, i_B = 0;
            while(i_A < intA_sz && i_B < intB_sz) {
                int intersect_L = max(A_intervals[i_A].L, B_intervals[i_B].L);
                intersect_L = max(intersect_L, 1);
                int intersect_R = min(A_intervals[i_A].R, B_intervals[i_B].R);
                
                if (intersect_L <= intersect_R) {
                    if (B_intervals[i_B].val != -1) {
                        int final_val = min(A_intervals[i_A].val, B_intervals[i_B].val);
                        updates1[final_val].push_back({intersect_L, intersect_R});
                    } else {
                        updates2[A_intervals[i_A].val].push_back({intersect_L, intersect_R});
                    }
                }
                
                if (A_intervals[i_A].R < B_intervals[i_B].R) i_A++;
                else i_B++;
            }
        }
    }
    
    // Evaluate via raw array DSU mappings
    for(int X = N; X >= 1; --X) {
        for(auto& p : updates1[X]) {
            int curr = find_dsu(dsu1_parent, p.L);
            while(curr <= p.R) {
                max_X1[curr] = X;
                dsu1_parent[curr] = curr + 1;
                curr = find_dsu(dsu1_parent, curr);
            }
        }
    }
    
    for(int X = N; X >= 1; --X) {
        for(auto& p : updates2[X]) {
            int curr = find_dsu(dsu2_parent, p.L);
            while(curr <= p.R) {
                max_X2[curr] = X;
                dsu2_parent[curr] = curr + 1;
                curr = find_dsu(dsu2_parent, curr);
            }
        }
    }
    
    long long ans = 0;
    for(int L = 1; L <= N; ++L) {
        int r = next_D[L];
        if (max_X1[L] > r) r = max_X1[L];
        
        int temp2 = max_X2[L] < next_D[L] ? max_X2[L] : next_D[L];
        if (temp2 > r) r = temp2;
        
        if (r > N) r = N;
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