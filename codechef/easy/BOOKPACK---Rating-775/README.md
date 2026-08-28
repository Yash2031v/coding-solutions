# BOOKPACK - Rating 775

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Packing Books

 *Chef is moving to a new house!* 

 *Unfortunately, this means he now has to pack up his things so that they can be moved too. Currently, Chef is packing up his (rather impressive) book collection into cardboard boxes.* 

Chef has $X$ shelves of books, each of which contains exactly $Y$ books. Each cardboard box can hold at most $Z$ books. In order to not mess up the organization of the books, Chef will also ensure that books from  **different shelves**  will  **not**  be placed in the same box.

Under these conditions, what is the minimum number of boxes needed to pack all the books?

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of one line of input, containing three space-separated integers $X, Y$, and $Z$: the values described in the statement.
### Output Format

For each test case, output on a new line one  **integer** : the minimum number of boxes needed to pack all the books.

### Constraints
- $1 \leq T \leq 1000$
- $1 \leq X, Y, Z \leq 1000$
### Sample 1:
Input
Output

```
4
5 9 9
5 9 7
2 3 2
22 34 12

```

```
5
10
4
66

```

### Explanation:

 **Test case $1$:**  Each box can hold $9$ books, and each shelf has $9$ books. So, Chef needs only five boxes: one for each shelf.

 **Test case $2$:**  Each box can hold $7$ books, and each shelf has $9$ books. So, Chef needs two boxes to hold all the books of one shelf (for example, one holding $4$ books and another one holding $5$). There are five shelves, so the total number of boxes needed is $5\times 2 = 10$.

 **Test case $3$:**  Each box can hold $2$ books, and each shelf has $3$ books. So, Chef needs two boxes to hold all the books of one shelf (for example, one holding $2$ books and another one holding $1$). There are two shelves, so the total number of boxes needed is $2\times 2 = 4$.

 **Test case $4$:**  Each shelf needs $3$ boxes to pack all its books. There are $22$ shelves, so the answer is $22\times 3 = 66$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-28T15:56:10.547Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    int g = y/z;
	    
	    if(y%z!=0){
	        g++;
	    }
	    cout<<x*g<<endl;
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/BOOKPACK)