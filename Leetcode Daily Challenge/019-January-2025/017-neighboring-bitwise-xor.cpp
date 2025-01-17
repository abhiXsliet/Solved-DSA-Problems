// https://leetcode.com/problems/neighboring-bitwise-xor/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    vector<int> buildArray(vector<int>& derived, int start, int n) {
        vector<int> original(n, start); // taking arr[0] = start
        for (int i = 0; i < n - 1; i ++) {
            original[i + 1] = derived[i] ^ original[i];
        }
        return original;
    }

    // TC : O(N)
    // SC : O(N)
    bool approach_1(vector<int>& derived) {
        int n = derived.size();
        // build original array by taking 0 as the starting element
        vector<int> original_1 = buildArray(derived, 0, n);   
        // build original array by taking 1 as the starting element
        vector<int> original_2 = buildArray(derived, 1, n);   

        return original_1[n - 1] ^ original_1[0] == derived[n - 1] || 
               original_2[n - 1] ^ original_2[0] == derived[n - 1];
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_2(vector<int>& derived) {
        int xor_all = 0;
        for (int &val : derived) {
            xor_all ^= val;
        }
        return xor_all == 0;
    }
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // return approach_2(derived);      // Build the original array
        return approach_1(derived);      // No need to build original array
    }
};