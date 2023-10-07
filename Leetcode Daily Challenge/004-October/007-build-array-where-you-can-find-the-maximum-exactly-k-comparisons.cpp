// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int t[51][51][101];
    
    int solve(int idx, int searchCost, int maxSoFar) {
        if(idx == N) {
            if(searchCost == K)
                return 1;
            return 0;
        }
        
        if(t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }
        
        int result = 0;
        
        for(int i = 1; i <= M; i++) {
            
            if(i > maxSoFar) {
                result = (result + solve(idx+1, searchCost+1, i)) % MOD;
            } else {
                result = (result + solve(idx+1, searchCost, maxSoFar)) % MOD;
            }
            
        }
        
        return t[idx][searchCost][maxSoFar] = result % MOD;
        
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0);
    }
};