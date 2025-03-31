// https://leetcode.com/problems/put-marbles-in-bags/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(N)
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> store;
        for (int i = 1; i < n; i ++) {
            store.push_back(weights[i] + weights[i - 1]);
        }

        sort(begin(store), end(store));
    
        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < k - 1; i ++) {
            minSum += store[i];
            maxSum += store[n - i - 2]; 
        }
        return maxSum - minSum;
    }
};