# GOODWEAT - Rating 835

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Good Weather

The weather report of Chefland is  *Good*  if the number of sunny days in a week is strictly greater than the number of rainy days.

Given $7$ integers $A_1, A_2, A_3, A_4, A_5, A_6, A_7$ where $A_i = 1$ denotes that the $i^{th}$ day of week in Chefland is a sunny day, $A_i = 0$ denotes that the $i^{th}$ day in Chefland is a rainy day. Determine if the weather report of Chefland is  *Good*  or not.

### Input Format
- First line will contain $T$, number of testcases. Then the testcases follow.
- Each testcase contains of a single line of input, $7$ space separated integers $A_1, A_2, A_3, A_4, A_5, A_6, A_7$.
### Output Format

For each testcase, print "YES" if the weather report of Chefland is Good, otherwise print "NO". Print the output without quotes.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

### Constraints
- $1 \leq T \leq 20$
- $0 \leq A_i \leq 1$
### Sample 1:
Input
Output

```
4
1 0 1 0 1 1 1
0 1 0 0 0 0 1
1 1 1 1 1 1 1
0 0 0 1 0 0 0

```

```
YES
NO
YES
NO
```

### Explanation:

 **Test case $1$:**  The number of sunny days is $5$ and the number of rainy days is $2$. Hence the weather report of Chefland is Good.

 **Test case $2$:**  The number of sunny days is $1$ and the number of rainy days is $6$. Hence the weather report of Chefland is not Good.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-29T07:01:03.831Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int arr[7];
	    for(int i=0;i<7;i++){
	        cin>>arr[i];
	    }int c=0;int y=0;
	    for(int x:arr){
	        if(x==1){
	            c++;
	        }
	        else{
	            y++;
	        }
	    }
	    if(c>y){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/GOODWEAT)