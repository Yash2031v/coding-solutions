# PLACEROOKS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Placing Rooks

You are given an $N \times M$ chessboard. You want to place as many rooks on it as possible, such that  **every rook attacks at most one other rook**.

A rook attacks another rook if they are in the same row or in the same column, and there is no other rook between them.

Find the maximum number of rooks you can place, and print one such placement.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of each test case contains two space-separated integers $N$ and $M$ — the number of rows and columns of the board.
### Output Format

For each test case, output on a new line the maximum number of rooks $K$.

Then, output $N$ lines, each containing a string of length $M$. The $j$-th character of the $i$-th of these lines should be `R` if there is a rook in row $i$ and column $j$, and `.` otherwise.

If there are multiple valid placements with $K$ rooks, you may print any of them.

### Constraints
- $1 \leq T \leq 100$
- $2 \leq N, M \leq 100$
### Sample 1:
Input
Output

```
3
2 2
3 3
2 5

```

```
2
R.
.R
4
R..
R..
.RR
4
RR...
..RR.

```

### Explanation:

 **Test case $1$:**  With three rooks on a $2 \times 2$ board, one rook would share its row with one rook and its column with another, so it would attack two rooks. Two rooks placed diagonally do not attack each other at all.

 **Test case $2$:**  The rooks in cells $(1, 1)$ and $(2, 1)$ attack only each other, and so do the rooks in cells $(3, 2)$ and $(3, 3)$.

 **Test case $3$:**  A row can hold at most $2$ rooks (with three rooks in a row, the middle one attacks two rooks), so $4$ rooks is the maximum.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T16:11:34.227Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n, string(m, '.'));
    vector<pair<int, int>> rooks;

    auto can_add = [&](int r, int c) {
        if (grid[r][c] == 'R') return false;
        int row_cnt = 0, col_cnt = 0;
        for (int j = 0; j < m; ++j) if (grid[r][j] == 'R') ++row_cnt;
        for (int i = 0; i < n; ++i) if (grid[i][c] == 'R') ++col_cnt;
        return row_cnt < 2 && col_cnt < 2;
    };

    auto attacks_count = [&](int r, int c) {
        int atk = 0;
        // Left neighbor in row r
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j] == 'R') { ++atk; break; }
        }
        // Right neighbor in row r
        for (int j = c + 1; j < m; ++j) {
            if (grid[r][j] == 'R') { ++atk; break; }
        }
        // Up neighbor in col c
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c] == 'R') { ++atk; break; }
        }
        // Down neighbor in col c
        for (int i = r + 1; i < n; ++i) {
            if (grid[i][c] == 'R') { ++atk; break; }
        }
        return atk;
    };

    auto valid_all = [&]() {
        for (auto [r, c] : rooks) {
            if (attacks_count(r, c) > 1) return false;
        }
        return true;
    };

    // Greedily add rooks only when every existing & new rook keeps attacks <= 1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!can_add(i, j)) continue;
            grid[i][j] = 'R';
            rooks.push_back({i, j});
            if (!valid_all()) {
                grid[i][j] = '.';
                rooks.pop_back();
            }
        }
    }

    cout << rooks.size() << '\n';
    for (const auto& row : grid) {
        cout << row << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/PLACEROOKS)