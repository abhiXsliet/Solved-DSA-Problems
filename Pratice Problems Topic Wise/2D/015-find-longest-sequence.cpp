// https://www.codingninjas.com/studio/problems/find-longest-sequence_893353



#include <bits/stdc++.h> 
using namespace std;

int N;
int dp[1001][1001];
vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// TC : O(N^2)
// SC : O(N^2)
int solve(vector<vector<int>>& mat, int i, int j) {
    if(!isSafe(i, j)) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1;

    for (auto& dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if (isSafe(new_i, new_j) && mat[new_i][new_j] - mat[i][j] == 1) {
            ans = max(ans, 1 + solve(mat, new_i, new_j));
        }
    }

    return dp[i][j] = ans;
}

// TC : O(N^2)
// SC : O(N^2)
int findLongestOverAll(vector<vector<int>> &mat, int n){  
    N = n;
    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, solve(mat, i, j));
        }
    }
    return ans;
}