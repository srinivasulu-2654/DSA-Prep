# 503. Next Greater Element II

[Leetcode Problem Link](https://leetcode.com/problems/next-greater-element-ii/description/)

## Steps:
1) This problem is quite different from the previous **Next Greater Element** problem.
2) Since the array is **circular**, we need to handle elements accordingly.
3) We use the **monotonic stack approach** like before, but with modifications:
   - Instead of iterating once, we iterate **twice** to simulate the circular nature.
   - Use `i % n` to access elements cyclically.
4) The loop should run from **`2 * n - 1` to `0`** to ensure we check all elements properly.

## Time Complexity:
- **O(n)** → Each element is pushed and popped from the stack at most once.

## Space Complexity:
- **O(n)** → Extra space for the stack and output array.

---
