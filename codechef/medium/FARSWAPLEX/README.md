# FARSWAPLEX

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Far Swapping (Ver 1)

You are given a permutation $P$ of the integers $[1, N]$. You can use the following operation as many times as you want:

- Choose an index $i$ ($1 \le i < N$) such that $|P_i - P_{i + 1}| > 1$
- Swap $P_i$ and $P_{i + 1}$.

Find the lexicographically minimal permutation that is possible using the above operations.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains a single integer $N$. The second line contains $N$ integers - $P_1, P_2, \ldots, P_N$.
### Output Format

For each test case, output $N$ integers - the lexicographically minimal permutation reachable by the operations.

### Constraints
- $1 \le T \le 10^4$
- $2 \le N \le 3000$
- $1 \le P_i \le N$
- $P_i \ne P_j$ for all $i \ne j$
- The sum of $N^2$ over all test cases does not exceed $3000^2$
### Sample 1:
Input
Output

```
3
3
1 3 2
3
3 2 1
5
5 2 3 1 4

```

```
1 3 2
3 2 1
2 1 3 5 4
```

### Explanation:

 **Test Case 1:**  $[1, 3, 2]$ and $[3, 1, 2]$ are reachable. The former is just the original permutation itself, and the latter can be reached by swapping $P_1$ and $P_2$. Note that $2 = P_3$ cannot be swapped with anybody due to the absolute difference $> 1$ condition.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-16T15:44:57.718Z  

```c_cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> P(N);
        vector<int> pos(N + 1);

        for (int i = 0; i < N; i++) {
            cin >> P[i];
            pos[P[i]] = i;
        }

        // Graph
        vector<vector<int>> adj(N + 1);
        vector<int> indegree(N + 1, 0);

        // Only consecutive values matter
        for (int x = 1; x < N; x++) {
            if (pos[x] < pos[x + 1]) {
                adj[x].push_back(x + 1);
                indegree[x + 1]++;
            } else {
                adj[x + 1].push_back(x);
                indegree[x]++;
            }
        }

        // Min-heap for lexicographically smallest topological sort
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                pq.push(i);
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();

            ans.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    pq.push(v);
                }
            }
        }

        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/FARSWAPLEX)