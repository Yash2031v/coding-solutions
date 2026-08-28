# CUTPAPER - Rating 800

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Paper Cutting

Chef has a  **square-shaped**  chart paper with the side length equal to $N$. He wants to cut out $K \times K$ squares from this chart paper.

Find the  **maximum**  number of $K \times K$ squares he can cut from the entire chart paper.

Note that, some part of the chart paper might not be a included in any $K \times K$ cutout square.

### Input Format
- The first line contains a single integer $T$ — the number of test cases. Then the test cases follow.
- The first and only line of each test case contains two space-separated integers $N$ and $K$ — the side length of the entire chart paper and the side length of the cutout squares.
### Output Format

For each test case, output on a new line the  **maximum**  number of $K \times K$ squares Chef can cut from the entire chart paper.

### Constraints
- $1 \leq T \leq 1000$
- $1 \leq K \le N \leq 1000$
### Sample 1:
Input
Output

```
3
5 1
2 2
5 2

```

```
25
1
4

```

### Explanation:

 **Test case 1:**  Chef can cut out $25$ squares of size $1 \times 1$ from the entire $5 \times 5$ chart paper.

 **Test case 2:**  Chef can cut out $1$ square of size $2 \times 2$ from the entire $2 \times 2$ chart paper.

 **Test case 3:**  Chef can cut out $4$ squares of size $2 \times 2$ from the entire $5 \times 5$ chart paper.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-28T15:39:02.770Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>n>>k;
	    cout << (n / k) * (n/k) << endl;
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/CUTPAPER)