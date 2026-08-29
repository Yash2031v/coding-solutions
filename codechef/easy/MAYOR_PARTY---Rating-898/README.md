# MAYOR_PARTY - Rating 898

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Peaceful Party

The mayor of your city has decided to throw a party to gather the favour of his people in different regions of the city.

There are $3$ distinct regions in the city namely $A$, $B$, $C$ comprising of $P_A$, $P_B$ and $P_C$ number of people respectively.

However, the mayor knows that people of the region $B$ are in conflict with people of regions $A$ and $C$. So, there will be a conflict if people from region $B$ are present at the party along with people from region $A$ or $C$.

The mayor wants to invite as many people as possible and also avoid any conflicts. Help him invite  **maximum**  number of people to the party.

### Input Format
- The first line contains a single integer $T$ - the number of test cases. Then the test cases follow.
- The first line of each test case contains three integers $P_A$, $P_B$ and $P_C$ - number of people living in regions $A$, $B$ and $C$ respectively.
### Output Format

For each test case, output the  **maximum**  number of people that can be invited to the party.

### Constraints
- $1 \leq T \leq 1000$
- $1 \leq P_A, P_B, P_C \leq 1000$
### Sample 1:
Input
Output

```
3
2 3 4
1 5 2
8 8 8

```

```
6
5
16

```

### Explanation:

 **Test case-1:**  Mayor can invite all the people from region $A$ and $C$. So the maximum number of people invited is $6$.

 **Test case-2:**  Mayor can invite all the people from region $B$. So the maximum number of people invited is $5$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-29T07:24:27.338Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    if(a+c>b){
	        cout<<a+c<<endl ;
	    }else{
	        cout<<b<<endl;
	    }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/MAYOR_PARTY)