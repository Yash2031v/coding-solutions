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
**Submitted:** 2026-11-04T15:30:08.139Z  

```c_cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int mRow = n, mxRow = -1;
        int mCol = m, mxCol = -1;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < m; j++) {
                if (s[j] == '1') {
                    mRow = min(mRow, i);
                    mxRow = max(mxRow, i);

                    mCol = min(mCol, j);
                    mxCol = max(mxCol, j);
                }
            }
        }

        int h = mxRow-mRow+1;
        int w = mxCol-mCol+1;
        cout<<h*w<<endl;
    }

    return 0;
}

```

---

[View on CodeChef](https://www.codechef.com/problems/FIVECOIN)