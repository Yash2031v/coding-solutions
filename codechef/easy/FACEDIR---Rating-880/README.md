# FACEDIR - Rating 880

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Find the Direction

Chef is currently facing the north direction. Each second he rotates exactly $90$ degrees in clockwise direction. Find the direction in which Chef is facing after exactly $X$ seconds.

$\textbf{Note}:$ There are only 4 directions: North, East, South, West (in clockwise order).

### Input Format
- First line will contain $T$, number of testcases. Then the testcases follow.
- Each testcase contains of a single integer $X$.
### Output Format

For each testcase, output the direction in which Chef is facing after exactly $X$ seconds.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq X \leq 1000$
### Sample 1:
Input
Output

```
3
1
3
6

```

```
East
West
South

```

### Explanation:

Chef is facing North in the starting.

 **Test Case $1$:**  After $1$ second he turns $90$ degrees clockwise and now faces the east direction.

 **Test Case $2$:**  Direction after $1$ second- east

Direction after $2$ seconds- south

Direction after $3$ seconds- west

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-29T07:10:29.519Z  

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
        switch(x%4){
            case 1:
            cout<<"EAST"<<endl;
            break;
            case 2:
            cout<<"SOUTH"<<endl;
            break;
            case 3:
            cout<<"WESt"<<endl;
            break;
            default:
            cout<<"NORTH"<<endl;
        }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/FACEDIR)