// https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N + M) where N = left.size() and M = right.size()
    // SC : O(1)
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastTime = INT_MIN;
        for (int i = 0; i < right.size(); i ++) {
            lastTime = max(lastTime, n - right[i]);
        }
        for (int i = 0; i < left.size(); i ++) {
            lastTime = max(lastTime, left[i]);
        }
        return lastTime;
    }
};