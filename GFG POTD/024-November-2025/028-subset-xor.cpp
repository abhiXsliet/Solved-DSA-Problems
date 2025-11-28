// https://www.geeksforgeeks.org/problems/subset-xor--175953/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // XOR of 1..n
        int S;
        if(n % 4 == 0) S = n;
        else if(n % 4 == 1) S = 1;
        else if(n % 4 == 2) S = n + 1;
        else S = 0;

        // If full set already satisfies XOR == n
        if (S == n) {
            vector<int> ans(n);
            for(int i = 1; i <= n; i++) ans[i-1] = i;
            return ans;
        }
        
        // Else remove the required number
        int missing = S ^ n;
        vector<int> ans;
        ans.reserve(n-1);
        for(int i = 1; i <= n; i++)
            if(i != missing) ans.push_back(i);
        return ans;
    }
};