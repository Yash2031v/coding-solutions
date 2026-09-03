# JASSIGNMENTS - Rating 513

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Janmansh and Assignments

Janmansh has to submit $3$ assignments for Chingari before $10$ pm and he starts to do the assignments at $X$ pm. Each assignment takes him $1$ hour to complete. Can you tell whether he'll be able to complete all assignments on time or not?

### Input Format
- The first line will contain $T$ - the number of test cases. Then the test cases follow.
- The first and only line of each test case contains one integer $X$ - the time when Janmansh starts doing the assignments.
### Output Format

For each test case, output `Yes` if he can complete the assignments on time. Otherwise, output `No`.

You may print each character of `Yes` and `No` in uppercase or lowercase (for example, `yes`, `yEs`, `YES` will be considered identical).

### Constraints
- $1 \le T \le 10$
- $1 \le X \le 9$
### Sample 1:
Input
Output

```
2
7
9

```

```
Yes
No

```

### Explanation:

 **Test case-1:**  He can start at $7$pm and finish by $10$ pm. Therefore he can complete the assignments.

 **Test case-2:**  He can not complete all the $3$ assignments if he starts at $9$ pm.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-03T16:01:39.596Z  

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
	    if(x+3<=10){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/JASSIGNMENTS)