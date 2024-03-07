// https://leetcode.com/problems/max-chunks-to-make-sorted/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve_approach_1(vector<int>& arr) {
        int chunks    = 0;
        int maxImpact = -1;
        for (int i = 0; i < arr.size(); i++) {
            maxImpact = max(maxImpact, arr[i]);
                
            if (i == maxImpact)
                chunks ++;
        }
        return chunks;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        return solve_approach_1(arr);
    }
};