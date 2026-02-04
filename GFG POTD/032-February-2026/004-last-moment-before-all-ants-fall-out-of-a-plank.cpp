// https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0, mini = 0;
        for (int i = 0; i < n; i ++) {
            if (i < left.size())  maxi = max(maxi, left[i]);
            if (i < right.size()) mini = max(mini, n - right[i]);
        }
        return max(maxi, mini);
    }
};