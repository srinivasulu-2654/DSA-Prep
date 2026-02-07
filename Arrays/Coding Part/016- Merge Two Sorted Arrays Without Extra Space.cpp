https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839?leftPanelTabValue=PROBLEM

#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.

	int m = a.size();
	int n = b.size();

	vector<long long>res(m+n);
	int ind = 0;

	int left = 0,right = 0;
	
	while(left<m && right<n)
	{
		if(a[left]<=b[right]){
			res[ind] = a[left];
			left++;
			ind++;
		}
		else{
			res[ind] = b[right];
			right++;
			ind++;
		}
		
	}

	while(left<m) res[ind++] = a[left++];
	while(right<n) res[ind++] = b[right++];

	for(int i=0;i<m+n;i++){
		if(i<m) a[i] = res[i];
		else b[i-m] = res[i];
	}
	
}
