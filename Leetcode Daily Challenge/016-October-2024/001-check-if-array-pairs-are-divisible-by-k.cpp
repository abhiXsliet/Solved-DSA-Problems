// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(K)
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0); // indices (r) stores the freq of remainder r, where r = arr[i] % k

        for (int& num : arr) {
            int rem = (num % k + k) % k;
            freq[rem] ++;
        }

        // [5, 15, 20, 1] : here we get an odd freq[0]
        if (freq[0] % 2) return false; 

        for (int rem = 1; rem <= k/2; rem ++) {
            int nextHalf = k - rem;
            if (freq[nextHalf] != freq[rem]) 
                return false;
        }

        return true;
    }
};