// https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383




#include <bits/stdc++.h>
using namespace std;

// TC : O(N * M)
// SC : O(N * M)
string findLCS(int n, int m, string &s1, string &s2){
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = n - 1; i >= 0; i --) {
		for (int j = m - 1; j >= 0; j --) {
			int take = 0;
			if (s1[i] == s2[j]) {
				take = 1 + dp[i + 1][j + 1];
			} 
			int notTake = max(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j]    = max(take, notTake);
		}
	}

	string lcs;
	int lcsSize = dp[0][0];
	if (lcsSize == 0) return "";

    // Printing LCS from the starting of both the strings
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (s1[i] == s2[j] && dp[i][j] == 1 + dp[i + 1][j + 1]) {
			lcs += s1[i];
			i ++, j ++;
		} else if (dp[i + 1][j] >= dp[i][j + 1]){
			i ++;
		} else {
			j ++;
		}
	}

	return lcs;
}