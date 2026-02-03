class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == e1) {
                cnt1++;
            } else if (nums[i] == e2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                e1 = nums[i];
            } else if (cnt2 == 0) {
                cnt2 = 1;
                e2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == e1) {
                cnt1++;
            } else if (nums[i] == e2) {
                cnt2++;
            }
        }

        vector<int> ans;
        if (cnt1 > n / 3) {
            ans.push_back(e1);
        }
        if (cnt2 > n / 3) {
            ans.push_back(e2);
        }

        return ans;
    }
};
