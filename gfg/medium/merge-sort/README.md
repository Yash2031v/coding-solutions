# Merge Sort

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.

 **Examples:** 

```
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: We get the sorted array after using merge sort

```

```
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: We get the sorted array after using merge sort 
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-17T15:15:07.864Z  

```cpp
class Solution {
  public:
  vector<int>c;
    void merge(vector<int>&item,int low,int high,int mid){
        c.resize(item.size());
        int i = low;
        int j = mid+1;
        int k = low;
        
        while(i<=mid && j<=high){
            if(item[i]<item[j]){
                c[k]=item[i];
                i++;
                k++;
            }else{
                c[k]=item[j];
                j++;
                k++;
            }

        }
        while(i<=mid){
            c[k]=item[i];
            i++;
            k++;
        }
        while(j<=high){
            c[k]=item[j];
            k++;
            j++;
        }
        int t = 0;
        for(int i = low; i <= high; i++){
        item[i] = c[i];
        }
    }
    void mergeSort(vector<int>&item,int low,int high){
        int mid = (low+high)/2;
        if(low<high){
            mid = (low+high)/2;
            mergeSort(item,low,mid);
            mergeSort(item,mid+1,high);
            merge(item,low,high,mid);

        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/merge-sort/1)