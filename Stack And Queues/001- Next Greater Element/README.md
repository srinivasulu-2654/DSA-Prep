## [Next Greater Element](https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1)
### Medium
---
Given an array `arr` of size `N`, for each element, find the **Next Greater Element (NGE)**.

The Next Greater Element for an element `x` is the first greater element on the right side of `x` in the array. If no greater element exists, print `-1`.

---

### **Steps to Solve:**
1️⃣ Traverse from **back** of the array.  
2️⃣ If the **stack** is empty, then `nge[i] = -1`.  
3️⃣ Otherwise, `nge[i] = st.top()`.  
4️⃣ If `nums[i] >= st.top()`, then pop all the elements until the while loop breaks.  
5️⃣ Return `nge`.

---

### **Example:**
```java
Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
