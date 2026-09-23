# NOTEBOOK - Rating 563

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Count the Notebooks

You know that $1$ kg of pulp can be used to make $1000$ pages and $1$ notebook consists of $100$ pages.

Suppose a notebook factory receives $N$ kg of pulp, how many notebooks can be made from that?

### Input Format
- First line will contain $T$, the number of test cases. Then the test cases follow.
- Each test case contains a single integer $N$ - the weight of the pulp the factory has (in kgs).
### Output Format

For each test case, output the number of notebooks that can be made using $N$ kgs of pulp.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq N \leq 100$
### Sample 1:
Input
Output

```
3
1
100
50

```

```
10
1000
500

```

### Explanation:

 **Test case-1:**  $1$ kg of pulp can be used to make $1000$ pages which can be used to make $10$ notebooks.

 **Test case-2:**  $100$ kg of pulp can be used to make $100000$ pages which can be used to make $1000$ notebooks.

 **Test case-3:**  $50$ kg of pulp can be used to make $50000$ pages which can be used to make $500$ notebooks.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-23T17:13:26.467Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<x*10<<endl;
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/NOTEBOOK)