# STONEMOV

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Stone Moving

There are $N$ piles of stones, the $i$-th pile containing $A_i$ stones.

Consider the process as follows:

- For $i = 1, 2, \ldots, N$ (in this order): Let $X = \min(A_i, N - i)$ Move $1$ stone from the pile numbered $i$ to each of the piles numbered $i + 1, i + 2, i + 3, \ldots, i + X$.

Find the total number of stones moved by the process above.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line contains a single integer $N$. The second line contains $N$ integers - $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, output on a new line the total number of stones moved.

### Constraints
- $1 \le T \le 10^4$
- $2 \le N \le 2 \cdot 10^5$
- $0 \le A_i \le N$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
4
3
3 3 3
3
1 0 1
6
2 0 3 0 1 4
2
0 0

```

```
3
2
8
0
```

### Explanation:

 **Test Case 1:**  The process happens as follows:

- $i = 1$ : $X = 2$, and we move $1$ stone from pile $1$ to each of $2$ and $3$. The resulting array $A$ is $[1, 4, 4]$.
- $i = 2$ : $X = 1$, and the array updates to $[1, 3, 5]$.
- $i = 3$ : $X = 0$, no further stone moves.

The total number of stones moved is $3$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-11T16:28:42.224Z  

```c_cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Using 1-based indexing for ease of implementation
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Difference array to keep track of range additions.
    // Size is N + 2 to safely accommodate diff[i + X + 1] when i + X = N.
    vector<long long> diff(N + 2, 0);
    
    long long current_add = 0;
    long long total_moved = 0;

    for (int i = 1; i <= N; ++i) {
        // Accumulate the sweep line difference to know the actual incoming stones
        current_add += diff[i];
        
        // Compute the actual number of stones at pile i presently
        long long current_stones = A[i] + current_add;
        
        // Number of stones we are moving from this pile
        long long X = min(current_stones, (long long)(N - i));
        total_moved += X;

        // Apply range updates for the stones being distributed forward
        if (X > 0) {
            diff[i + 1] += 1;
            diff[i + X + 1] -= 1;
        }
    }

    cout << total_moved << "\n";
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

[View on CodeChef](https://www.codechef.com/problems/STONEMOV)