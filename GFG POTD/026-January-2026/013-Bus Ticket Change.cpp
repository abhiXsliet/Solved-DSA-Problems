// https://www.geeksforgeeks.org/problems/lemonade-change/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    bool canServe(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            if (arr[i] == 5) {
                mpp[arr[i]] ++;
            } else if (arr[i] == 10) {
                if (mpp[5] >= 1) {
                    mpp[arr[i]] ++;
                    mpp[5] --;
                } else return false;
            } else {
                if (mpp[10] >= 1 && mpp[5] >= 1) {
                    mpp[10] --;
                    mpp[5] --;
                } else if (mpp[5] >= 3) {
                    mpp[5] -= 3;
                } else return false;
            }
        }
        return true;
    }
};