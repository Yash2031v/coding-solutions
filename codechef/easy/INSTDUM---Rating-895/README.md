# INSTDUM - Rating 895

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Inside The Stadium

Shubman Gill is playing an international match.
He played a total of $N$ balls, where, in the $i^{th}$ ball, he scored $A_{i}$ runs.

The  *strike rate*  of a player is calculated as : $\frac{\text{no. of runs}}{\text{no. of balls played}}\times 100$.

Preet, a math enthusiast, is currently watching the match. Help him find the number of times, Shubman's  *strike rate*  became  **exactly**  $100$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains an integer $N$ - the total number of balls played by Gill. The second line of each test case contains $N$ space-separated integers where $A_{i}$ denotes runs scored on $i^{th}$ ball.
### Output Format

For each test case, output on a new line, the total number of times the strike rate of Gill became $100$.

### Constraints
- $1 \leq T \leq 10^{5}$
- $1 \leq N \leq 10^{5}$
- $0 \leq A_i \leq 6$
- The sum of $N$ over all test cases won't exceed $10^{6}$.
### Sample 1:
Input
Output

```
3
4
1 0 2 3
5
2 6 0 1 0
3
1 1 1
```

```
2
0
3
```

### Explanation:

 **Test case $1$:**  Shubhman's strike rate would be:

- After $1$ ball: $\frac{\text{1}}{\text{1}}\times 100 = 100$.
- After $2$ balls: $\frac{\text{1}}{\text{2}}\times 100 = 50$.
- After $3$ balls: $\frac{\text{3}}{\text{3}}\times 100 = 100$.
- After $4$ balls: $\frac{\text{6}}{\text{4}}\times 100 = 150$.

Thus, the strike rate was exactly $100$ twice.

 **Test case $2$:**  Shubhman's strike rate would be:

- After $1$ ball: $\frac{\text{2}}{\text{1}}\times 100 = 200$.
- After $2$ balls: $\frac{\text{8}}{\text{2}}\times 100 = 400$.
- After $3$ balls: $\frac{\text{8}}{\text{3}}\times 100 = 266.66$.
- After $4$ balls: $\frac{\text{9}}{\text{4}}\times 100 = 225$.
- After $5$ balls: $\frac{\text{9}}{\text{5}}\times 100 = 180$.

Thus the strike rate was never exactly $100$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-29T07:21:49.542Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int sum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            sum += arr[i];

            if (sum == i) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/INSTDUM)