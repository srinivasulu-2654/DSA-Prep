#include <bits/stdc++.h>
using namespace std;

// Function to apply range updates using Difference Array Technique
vector<int> applyDifferenceArray(int n, vector<vector<int>>& updates) {
    // Step 1: Initialize difference array of length n
    vector<int> diff(n, 0);

    // Step 2: Traverse updates vector and apply the range modifications
    for (auto query : updates) {
        int left = query[0];
        int right = query[1];
        int x = query[2];

        diff[left] += x;
        if (right + 1 < n) 
            diff[right + 1] -= x;
    }

    // Step 3: Compute the final array from the difference array using prefix sum
    vector<int> res(n, 0);
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += diff[i];
        res[i] = currSum;
    }

    return res;
}

int main() {
    // Example input
    int n = 5;
    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};

    // Compute the final result after applying all updates
    vector<int> result = applyDifferenceArray(n, updates);

    // Print the final modified array
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
