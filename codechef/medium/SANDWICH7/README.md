# SANDWICH7

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Sandwiches

Chef is running a sandwich shop. He has $B$ pieces of bread, $H$ pieces of ham, and $C$ pieces of cheese.

To make a sandwich, Chef uses $2$ pieces of bread, and one piece of either ham or cheese, not both.

Find the maximum number of sandwiches Chef can make.

### Input Format
- The first line contains $3$ integers - $B$, $H$ and $C$.
### Output Format

Output the maximum number of sandwiches Chef can make.

### Constraints
- $1 \le B, H, C \le 10$
### Sample 1:
Input
Output

```
8 3 1

```

```
4

```

### Explanation:

Chef can make $3$ ham sandwiches, and $1$ cheese sandwich, using exactly $8$ pieces of bread, $3$ pieces of ham, and $1$ piece of cheese.

### Sample 2:
Input
Output

```
3 2 2

```

```
1

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T16:30:11.448Z  

```c_cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int B, H, C;
    if (cin >> B >> H >> C) {
        cout << min(B / 2, H + C) << endl;
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/SANDWICH7)