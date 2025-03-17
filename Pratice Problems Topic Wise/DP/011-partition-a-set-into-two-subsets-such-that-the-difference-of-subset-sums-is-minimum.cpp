// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494


// using subset sum logic
// similar : https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?


#include <bits/stdc++.h>
using namespace std;

void bottom_up(vector<int> &arr, int n, int target, vector<vector<int>> &dp) {
	for (int j = 0; j <= n; j ++) {
		dp[j][0] = 1;   // making target == 0 always possible by choosing no elements
	}
	
	for (int i = n - 1; i >= 0; i --) {
		for (int tar = 1; tar <= target; tar ++) {
			int take = 0;
			if (tar - arr[i] >= 0) 
				take = dp[i + 1][tar - arr[i]];
			int notT = dp[i + 1][tar];

			dp[i][tar] = (take | notT);
		}
	}
}

int approach_1(vector<int> &nums, int n) {
	int total = accumulate(begin(nums), end(nums), 0);
	
	vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
	bottom_up(nums, n, total, dp);

	int minDiff = INT_MAX;
	for (int s1 = 0; s1 <= total/2; s1 ++) {
		if (dp[0][s1])
			minDiff = min(minDiff, abs((total - s1) - s1));
	}
	return minDiff;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	return approach_1(arr, n);  // watch gfg submission for more clear code
}