// https://www.geeksforgeeks.org/problems/maximum-subarray-sum--110820/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        
        // Step 1: Build prefix sums
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + arr[i];
        }
        
        // Step 2: Sliding window min using deque
        deque<int> dq;  // stores indices of prefix sums
        long long ans = LLONG_MIN;
        
        for (int r = a; r <= n; r++) {
            // add candidate index (r-a) into deque
            int idxAdd = r - a;
            while (!dq.empty() && pref[dq.back()] >= pref[idxAdd]) dq.pop_back();
            dq.push_back(idxAdd);
            
            // remove indices out of range [r-b, r-a]
            int minIdx = r - b;
            if (!dq.empty() && dq.front() < minIdx) dq.pop_front();
            
            // now best l = dq.front()
            ans = max(ans, pref[r] - pref[dq.front()]);
        }
        
        return (int)ans;
    }
};