# Difference Array Technique

The **Difference Array Technique** is a famous method used to efficiently apply **range updates** to an array.  
It helps perform **multiple updates in constant time (O(1))** and is ideal for **range modification problems**.

### **Key Benefits:**
✅ Efficiently handles multiple range updates.  
✅ Reduces time complexity from **O(n) per update** to **O(1) per update**.  
✅ Commonly used in problems involving **cumulative range modifications**.

---

### **Usage**
1. Construct a **difference array** based on the input array.
2. Apply updates using **O(1) operations** on the difference array.
3. Compute the final array using **prefix sum**.

---

### **Example Usage**
#### **Problem:** Add `val` to every element in the range `[l, r]`
Instead of modifying the array directly, update the **difference array**:

1. **Increment `diff[l]` by `val`**  
2. **Decrement `diff[r+1]` by `val`**  
3. Compute the **final array** using a **prefix sum** of `diff[]`.

---

### **Complexity Analysis**
- **Building the difference array** → `O(n)`
- **Each update operation** → `O(1)`
- **Computing the final array** → `O(n)`

This makes it highly **efficient for range update problems**.

---


