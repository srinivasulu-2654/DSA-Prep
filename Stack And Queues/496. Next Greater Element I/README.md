## [496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
### Easy
---
Given two arrays `nums1` and `nums2`, find the **Next Greater Element** for each element in `nums1`.  
The **Next Greater Element** for an element `x` is the first greater element on the right side of `x` in `nums2`.  
If no greater element exists, return `-1`.

---

### **Steps to Solve:**
We can solve this problem using **two approaches**:

1️⃣ **Using Stack (Monotonic Stack)**
   - Traverse `nums2` from **right to left**.
   - Use a **stack** to track the Next Greater Element.
   - Store results in a **hash map (`unordered_map`)**.
   - For each element in `nums1`, look up its NGE from the **map**.

2️⃣ **Using Brute Force (Inefficient)**
   - Traverse `nums2` for each element in `nums1` (**O(n^2)** time complexity).
   - Not optimal for larger inputs.

---

### **Example:**
```cpp
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1, 3, -1]

Explanation:
- 4 → No greater element → -1
- 1 → Next greater is 3
- 2 → No greater element → -1

