# CLIPLX - Rating 1167

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### IPL and RCB

It's IPL time and as usual RCB are finding it tough to qualify for playoffs. RCB needs a minimum of $X$ more points to qualify for playoffs in their remaining $Y$ matches. A win, tie and loss in a match will yield $2,1,0$ points respectively to a team.

You being a true RCB supporter want to find the minimum number of matches RCB needs to win to qualify for playoffs. It is guaranteed that RCB will qualify for playoffs if they win all their remaining $Y$ matches.

### Input:
- First line will contain $T$, number of testcases. Then the testcases follow.
- Each testcase contains of a single line of input, two space separated integers $X, Y$
### Output:

For each testcase, output in a single line the minimum number of matches RCB must win to qualify for playoffs.

### Constraints :
- $1 \leq T \leq 10000$
- $1 \leq X \leq 100$
- $1 \leq Y \leq 100$
- $1 \leq X \leq 2\cdot Y$
### Sample 1:
Input
Output

```
2
10 5
1 5
```

```
5
0
```

### Explanation:
- In first case $X=10$ and $Y=5$, so RCB needs $10$ points from remaining $5$ matches to qualify for playoffs. It is only possible if they win all their remaining $5$ matches.
- In second case $X=1$ and $Y=5$, so RCB needs $1$ points from their remaining $5$ matches to qualify for playoffs. It can be done if they tie any one of their $5$ matches and lose the remaining $4$. So they need to win $0$ matches.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-28T15:26:15.679Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    if(x>y){
	        cout<<x-y<<endl;
	    }
	    else{
	        cout<<0<<endl;
	    }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/CLIPLX)