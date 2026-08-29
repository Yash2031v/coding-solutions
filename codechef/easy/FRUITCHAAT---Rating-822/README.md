# FRUITCHAAT - Rating 822

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Chef and His Fruit Stand

Chef has closed his restaurant and decided to run a fruit stand instead. His signature dish is a fruit chaat consisting of $2$ bananas and $1$ apple. He currently has $X$ bananas and $Y$ apples. How many chaats can he make with the fruits he currently has?

### Input Format
- The first line will contain $T$, the number of testcases. Then the testcases follow.
- Each testcase consists of a single line containing two space separated integers - $X$ and $Y$
### Output Format

For each testcase, output the answer on a new line.

### Constraints
- $1 \leq T \leq 100$
- $0 \leq X, Y \leq 100$
### Sample 1:
Input
Output

```
3
72 50
38 93
51 4
```

```
36
19
4

```

### Explanation:

 **Test Case $1$:**  Chef can make $36$ chaats using $72$ bananas and $36$ apples.

 **Test Case $2$:**  Chef can make $19$ chaats using $38$ bananas and $19$ apples.

 **Test Case $3$:**  Chef can make $4$ chaats using $8$ bananas and $4$ apples.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-29T07:04:40.051Z  

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
	    if((x/2)<y){
	        cout<<x/2<<endl;
	    }
	    else{
	        cout<<y<<endl;
	    }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/FRUITCHAAT)