# FIVECOIN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Exact Change

You want to pay exactly $N$ rupees to a shop.
You have  **one**  coin worth $5$ rupees and an unlimited supply of coins worth $1$ rupee each.

Find the minimum number of coins you must use to pay exactly $N$ rupees. You may use the $5$-rupee coin at most once.

### Input Format
- The first and only line of input will contain a single integer $N$ — the amount to be paid, in rupees.
### Output Format

Output a single integer: the minimum number of coins required.

### Constraints
- $1 \leq N \leq 20$
### Sample 1:
Input
Output

```
3

```

```
3

```

### Explanation:

Use three $1$-rupee coins.

### Sample 2:
Input
Output

```
5

```

```
1

```

### Explanation:

Use the $5$-rupee coin.

### Sample 3:
Input
Output

```
8

```

```
4

```

### Explanation:

Use the $5$-rupee coin and three $1$-rupee coins.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-04T15:27:03.536Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    
    int min_r = N, max_r = -1;
    int min_c = M, max_c = -1;
    
    // Find the bounding box containing all '1's
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '1') {
                min_r = min(min_r, i);
                max_r = max(max_r, i);
                min_c = min(min_c, j);
                max_c = max(max_c, j);
            }
        }
    }
    
    // Calculate area of the smallest enclosing rectangle
    long long area = (long long)(max_r - min_r + 1) * (max_c - min_c + 1);
    cout << area << "\n";
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

[View on CodeChef](https://www.codechef.com/problems/FIVECOIN)