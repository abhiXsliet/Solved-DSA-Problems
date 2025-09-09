// https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(1)
    int assignHole(vector<int>& mices, vector<int>& holes) {
        sort(begin(mices), end(mices));
        sort(begin(holes), end(holes));
        
        int minTime = INT_MIN;
        for (int i = 0; i < mices.size(); i ++) {
            minTime = max(minTime, abs(holes[i] - mices[i]));
        }
        return minTime;
    }
};