# PRB01 - Rating 794

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Primality Test

Alice and Bob are meeting after a long time. As usual they love to play some math games. This times Alice takes the call and decides the game. The game is very simple, Alice says out an integer and Bob has to say whether the number is prime or not. Bob as usual knows the logic but since Alice doesn't give Bob much time to think, so Bob decides to write a computer program.

Help Bob accomplish this task by writing a computer program which will calculate whether the number is prime or not.

Note that 1 is not a prime number.

### Input

The first line of the input contains an integer T, the number of testcases. T lines follow.

Each of the next T lines contains an integer N which has to be tested for primality.

### Output

For each test case output in a separate line, "yes" if the number is prime else "no."

### Constraints
- 1 ≤ T ≤ 20
- 1 ≤ N ≤ 100000
### Sample 1:
Input
Output

```
5
23
13
20
1000
99991
```

```
yes
yes
no
no
yes
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-20T16:53:01.269Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
void checkprime(int n ){
    if(n==0||n==1){
        cout<<"NO"<<endl;
        return;
    }
    int count=0;
	    for(int i=2;i<n/2;i++){
	        if(n%i==0){
	            count++;
	        }
	    }
	    if(count!=0){
	        cout<<"NO"<<endl;
	    }else{
	            cout<<"Yes"<<endl;
	        }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    checkprime(n);
	    
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/PRB01)