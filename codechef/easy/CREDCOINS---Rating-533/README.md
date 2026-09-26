# CREDCOINS - Rating 533

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-26T17:13:25.246Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++){
	    cin>>arr[i];
	}
	int count = 0;
	for(int x:arr){
	    if(x%2==0){
	        count++;
	    }
	}
	if(count>n - count){
	    cout<<"READY FOR BATTLE"<<endl;
	}else{
	    cout<<"NOT READY"<<endl;
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/CREDCOINS)