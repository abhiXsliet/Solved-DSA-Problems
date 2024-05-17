// https://leetcode.com/contest/weekly-contest-397/problems/taking-maximum-energy-from-the-mystic-dungeon/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> store = energy;
        
        for (int i = k; i < n; i++) {
            store[i] = max(store[i], store[i] + store[i - k]);
        }

        int ans = INT_MIN;
        for (int i = n - k; i < n; i++) {
            ans = max(ans, store[i]);
        }
        return ans;
    }
};