// https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    bool better(vector<int> &arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        int idx = n - 1;
        while (idx >= 0) {
            int i = 0, j = idx - 1;
            int cSq = arr[idx] * arr[idx];
            while (i < j) {
                int aSq = arr[i] * arr[i];
                int bSq = arr[j] * arr[j];

                if (aSq + bSq == cSq) return true;
                else if (aSq + bSq < cSq) i ++;
                else j --;
            }
            idx --;
        }
        
        return false;
    }
    
    // TC : O(N + max(arr[i]^2))
    // SC : O(max(arr[i]^2))
    bool optimal(vector<int> &arr) {
        int n = arr.size();
        
        int maxSq = 0;
        for (int &num : arr) {
            num  *= num;
            maxSq = max(maxSq, num);
        }
        
        vector<int> freq(maxSq + 1, 0);
        for (int &num : arr) {
            freq[num] ++;
        }
        
        // fix cSq from 1 to maxSq
        for (int cSq = 1; cSq <= maxSq; cSq ++) {
            if (freq[cSq] == 0) continue;
            
            // try aSq from 1 to cSq/2
            for (int aSq = 1; aSq <= cSq/2; aSq ++) {
                int bSq = cSq - aSq;
                if (bSq < 0) continue;
                
                if (aSq == bSq) {
                    if (freq[aSq] >= 2) return true;
                } else {
                    if (freq[aSq] >= 1 && freq[bSq] >= 1) return true;
                }
            }
        }
        return false;
    }
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // return better(arr);     // TLE
        
        return optimal(arr);
    }
};