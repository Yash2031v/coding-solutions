# SUGARCANE - Rating 562

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-28T17:06:19.003Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b,x,y;
	    cin>>a>>b>>x>>y;
	    if((a*b)<=(x*y)){
	        cout<<"yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/SUGARCANE)