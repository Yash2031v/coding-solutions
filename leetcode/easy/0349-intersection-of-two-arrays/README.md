# Intersection of Two Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two integer arrays `nums1` and `nums2`, return  *an array of their intersection*. Each element in the result must be  **unique**  and you may return the result in  **any order**.

 

 **Example 1:** 

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

```

 **Example 2:** 

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

```

 

 **Constraints:** 

- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000

## Solution

**Language:** Python  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.4 MB (beats 66.94%)  
**Submitted:** 2026-10-04T15:41:39.867Z  

```py
class Solution(object):
    def intersection(self, nums1, nums2):
        return list(set(nums1) & set(nums2))
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
```

---

[View on LeetCode](https://leetcode.com/problems/intersection-of-two-arrays/)