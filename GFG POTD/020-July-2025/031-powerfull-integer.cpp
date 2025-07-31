// https://www.geeksforgeeks.org/problems/powerfull-integer--170647/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N + maxi)
    // SC : O(maxi)
    int approach_1(vector<vector<int>> &intervals, int k) {
        int maxi = -1;
        for (vector<int> &interval : intervals) {
            if (interval[1] > maxi) {
                maxi = interval[1];
            }
        }
        
        vector<int> freq(maxi + 2, 0);
        for (vector<int> &interval : intervals) {
            freq[interval[0]]     += 1;
            freq[interval[1] + 1] -= 1;
        }
        
        int result = -1;
        for (int i = 1; i <= maxi; i ++) {
            freq[i] += freq[i - 1];
            if (freq[i] >= k) {
                result = i;
            }
        }
        
        return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<vector<int>> &intervals, int k) {
        map<int, int> mpp;
        for (auto &interval : intervals) {
            mpp[interval[0]] += 1;
            mpp[interval[1] + 1] -= 1;
        }
    
        int active = 0;
        int result = -1;
        int prev = -1;
    
        for (auto it = mpp.begin(); it != mpp.end(); ++it) {
            int point = it->first;
            if (prev != -1 && active >= k) {
                // all values from prev to point - 1 are powerful
                result = point - 1; 
            }
    
            active += it->second;
            prev = point;
        }
    
        return result;
    }
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // return approach_1(intervals, k);    // mle
        return approach_2(intervals, k);
    }
};