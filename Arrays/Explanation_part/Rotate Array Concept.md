Array Rotation (Right & Left Shift)

Overview

This document explains how to perform Right Shift (Clockwise Rotation) and Left Shift (Counterclockwise Rotation) on an array.

Example

Given an array:

arr[] = {1,2,3,4,5}

Right Shift (Clockwise)

Output: [5,1,2,3,4]

Left Shift (Counterclockwise)

Output: [2,3,4,5,1]

Right Shift (Clockwise Rotation)

int ele = arr[n-1];  // Store last element
for(int i = n-1; i >= 1; i--) {
    arr[i] = arr[i-1];
}
arr[0] = ele;  // Move last element to the front

Left Shift (Counterclockwise Rotation)

int ele = arr[0];  // Store first element
for(int i = 0; i < n-1; i++) {
    arr[i] = arr[i+1];
}
arr[n-1] = ele;  // Move first element to the back

Complete C++ Code

#include <bits/stdc++.h>
using namespace std;

void rightShift(vector<int>& arr) {  // Right Shift (Clockwise)
    int n = arr.size();
    int ele = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = ele;
}

void leftShift(vector<int>& arr) {  // Left Shift (Counterclockwise)
    int n = arr.size();
    int ele = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = ele;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    rightShift(arr);
    cout << "After Right Shift: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    leftShift(arr);
    cout << "After Left Shift: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}

Expected Output

Original Array: 1 2 3 4 5
After Right Shift: 5 1 2 3 4
After Left Shift: 1 2 3 4 5

