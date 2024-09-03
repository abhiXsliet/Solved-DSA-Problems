// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
	private:
	int m;
	int n;
	int dp[1001][1001];
	
	
	int LCS(string& s1, string& s2, int i, int j) {
	    if (i >= m || j >= n) return 0;
	    
	    if (dp[i][j] != -1) 
	        return dp[i][j];
	    
	    int lcsLen = 0;
	    if (s1[i] == s2[j]) {
	        lcsLen = 1 + LCS(s1, s2, i + 1, j + 1);
	    } else {
	        lcsLen = max(LCS(s1, s2, i + 1, j), LCS(s1, s2, i, j + 1));
	    }
	    return dp[i][j] = lcsLen;
	}
	
	int solve(string& s1, string& s2, int i, int j) {
	    if (i == m && j == n)
	        return 0;
	        
	    if (i < m && j >= n) 
	        return (m - i);
	        
	    if (i >= m && j < n)
	        return (n - j);
	        
	    if (dp[i][j] != -1) 
	        return dp[i][j];
	   
	    int ans = 0;
	    if (s1[i] == s2[j]) {
	        ans = solve(s1, s2, i + 1, j + 1);
	    } else {
	        int del = 1 + solve(s1, s2, i + 1, j);
	        int ins = 1 + solve(s1, s2, i, j + 1);
	        ans = min(del, ins);
	    }
	    
	    return dp[i][j] = ans;
	}
	
	// TC : O(M * N)
	// SC : O(M * N)
	int approach_1(string& str1, string& str2) {
	    m = str1.length();
	    n = str2.length();
	    memset(dp, -1, sizeof(dp));
	    return solve(str1, str2, 0, 0);
	}
	
	// TC : O(M * N)
	// SC : O(M * N)
	int approach_2(string& str1, string& str2) {
	    m = str1.length();
	    n = str2.length();
	    memset(dp, -1, sizeof(dp));
	    
	    int L = LCS(str1, str2, 0, 0);
	    
	   // cout << L << endl;
	    int insertCnt = n - L;
	    int deleteCnt = m - L;
	    
	    return insertCnt + deleteCnt;
	}
	public:
	int minOperations(string str1, string str2) 
	{ 
	   // return approach_1(str1, str2);  // without LCS
	   
	   return approach_2(str1, str2);   // Used LCS
	} 
};


//{ Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends