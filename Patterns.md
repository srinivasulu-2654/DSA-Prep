# DSA Patterns and Identification Guide

## 🔥 1. Sliding Window
### 👉 How to Identify?
✔ Given an array or string  
✔ Find a subarray/subsequence that meets a condition (max/min sum, longest substring, etc.)  
✔ Often has constraints like contiguous elements or fixed/variable window size  

### 🔹 Example Problems:
- Longest Substring Without Repeating Characters (LeetCode 3)
- Maximum Sum Subarray of Size K (LeetCode 209)
- Longest Subarray with Sum ≤ K (LeetCode 862)

### 🛠 Techniques:
✅ Fixed Window Size → Simple window of size K  
✅ Variable Window Size → Expand & contract dynamically  

---

## 🔥 2. Two Pointers
### 👉 How to Identify?
✔ Usually sorted arrays or linked lists  
✔ You need to find pairs or triplets that meet some condition  

### 🔹 Example Problems:
- Two Sum Sorted Array (LeetCode 167)
- 3Sum (LeetCode 15)
- Remove Duplicates from Sorted Array (LeetCode 26)

### 🛠 Techniques:
✅ Left & Right Pointers Approach  
✅ Move pointers based on condition (sum too high? move left or right)  

---

## 🔥 3. Fast & Slow Pointers (Tortoise & Hare)
### 👉 How to Identify?
✔ Usually used in Linked Lists & Cyclic Detection Problems  
✔ If the problem mentions cycle detection, middle of linked list, or repeated elements  

### 🔹 Example Problems:
- Detect Cycle in Linked List (LeetCode 141)
- Find Middle of Linked List (LeetCode 876)
- Find Duplicate Number (LeetCode 287)

### 🛠 Techniques:
✅ Use two pointers (slow moves 1 step, fast moves 2 steps)  

---

## 🔥 4. Merge Intervals
### 👉 How to Identify?
✔ Given intervals (start & end times)  
✔ Need to merge, find gaps, or sort them  

### 🔹 Example Problems:
- Merge Intervals (LeetCode 56)
- Insert Interval (LeetCode 57)
- Meeting Rooms II (LeetCode 253)

### 🛠 Techniques:
✅ Sort by start time → Then process intervals one by one  
✅ Use Stack or Two Pointers  

---

## 🔥 5. Cyclic Sort
### 👉 How to Identify?
✔ Given an array of range (1 to N) with missing/duplicate numbers  
✔ Problem asks you to find missing, duplicate, or first positive number  

### 🔹 Example Problems:
- Find All Missing Numbers (LeetCode 448)
- Find the Duplicate Number (LeetCode 287)
- First Missing Positive (LeetCode 41)

### 🛠 Techniques:
✅ Swap elements to their correct position  

---

## 🔥 6. Bit Manipulation
### 👉 How to Identify?
✔ Problem asks for odd/even check, power of 2, XOR operations, bit counts  

### 🔹 Example Problems:
- Single Number (LeetCode 136)
- Power of Two (LeetCode 231)
- Counting Bits (LeetCode 338)

### 🛠 Techniques:
✅ Use XOR to find unique numbers  
✅ Bitwise AND/OR for specific conditions  

---

## 🔥 7. Subsets / Combinations / Permutations (Backtracking)
### 👉 How to Identify?
✔ Problem asks for all possible combinations, subsets, or arrangements  
✔ Constraints are small (N ≤ 15-20)  

### 🔹 Example Problems:
- Subsets (LeetCode 78)
- Permutations (LeetCode 46)
- Combination Sum (LeetCode 39)

### 🛠 Techniques:
✅ DFS with recursion  
✅ Include/Exclude pattern  

---

## 🔥 8. Graphs (BFS/DFS, Dijkstra, Union-Find)
### 👉 How to Identify?
✔ Given a grid or connections between nodes  
✔ Asked to find shortest path, number of islands, cycles, connected components  

### 🔹 Example Problems:
- Number of Islands (LeetCode 200)
- Word Ladder (LeetCode 127)
- Course Schedule (LeetCode 207)

### 🛠 Techniques:
✅ BFS for shortest path problems  
✅ DFS for connected components  
✅ Dijkstra for weighted graphs  
✅ Union-Find for cycle detection  

---

## 🔥 9. Dynamic Programming (DP)
### 👉 How to Identify?
✔ Given a recursive problem with overlapping subproblems  
✔ Constraints are large (N ≤ 10^5) → Need optimized approach  
✔ Often asks for minimum/maximum ways to do something  

### 🔹 Example Problems:
- Climbing Stairs (LeetCode 70)
- Longest Increasing Subsequence (LeetCode 300)
- Knapsack Problem (Famous DP Problem)

### 🛠 Techniques:
✅ Top-down with Memoization  
✅ Bottom-up with DP table  

---

## 🔥 10. Trees (DFS, BFS, Binary Search Tree, LCA)
### 👉 How to Identify?
✔ Problem involves Binary Trees or BSTs  
✔ Asked to find lowest common ancestor, depth, diameter, etc.  

### 🔹 Example Problems:
- Lowest Common Ancestor (LeetCode 236)
- Diameter of Binary Tree (LeetCode 543)
- Binary Tree Level Order Traversal (LeetCode 102)

### 🛠 Techniques:
✅ BFS for level-order traversal  
✅ DFS for recursive solutions  
✅ Binary Search Property for BST problems  

---

## 📌 How to Identify DSA Problems Quickly?
🚀 Look at the input constraints:  
✔ Small Constraints (N ≤ 20) → Backtracking  
✔ Large Constraints (N ≥ 10^5) → Binary Search / DP / Greedy  
✔ Given Intervals → Sorting + Merge Intervals  
✔ Finding Pairs → Two Pointers or HashMap  
✔ Finding Shortest Path → BFS / Dijkstra  

---

