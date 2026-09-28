# EXPERT - Rating 561

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Expert Setter

A problem setter is called an  *expert*  if  **at least**  $50 \%$ of their problems are approved by Chef.

Munchy submitted $X$ problems for approval. If $Y$ problems out of those were approved, find whether Munchy is an  *expert*  or not.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of a two space-separated integers $X$ and $Y$ - the number of problems submitted and the number of problems that were approved by Chef.
### Output Format

For each test case, output on a new line `YES`, if Munchy is an  *expert*. Otherwise, print `NO`.

The output is case-insensitive. Thus, the strings `YES`, `yes`, `yeS`, and `Yes` are all considered the same.

### Constraints
- $1 \leq T \leq 1000$
- $1 \leq Y \le X \leq 10^6$
### Sample 1:
Input
Output

```
4
5 3
1 1
4 1
2 1

```

```
YES
YES
NO
YES
```

### Explanation:

 **Test case $1$:**  We are given that $3$ out of $5$ problems were approved. Thus, $60 \%$ of the problems were approved. Since at least $50 \%$ of the problems were approved, Munchy is an  *expert*.

 **Test case $2$:**  We are given that $1$ out of $1$ problems were approved. Thus, $100 \%$ of the problems were approved. Since at least $50 \%$ of the problems were approved, Munchy is an  *expert*.

 **Test case $3$:**  We are given that $1$ out of $4$ problems were approved. Thus, $25 \%$ of the problems were approved. Since at least $50 \%$ of the problems were not approved, Munchy is not an  *expert*.

 **Test case $4$:**  We are given that $1$ out of $2$ problems were approved. Thus, $50 \%$ of the problems were approved. Since at least $50 \%$ of the problems were approved, Munchy is an  *expert*.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-28T17:05:53.343Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        
        if(2*y>=x){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/EXPERT)