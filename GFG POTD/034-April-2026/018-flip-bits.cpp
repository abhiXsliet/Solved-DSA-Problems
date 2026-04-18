// https://www.geeksforgeeks.org/problems/flip-bits0240/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        int cntOnes = 0;
        
        for (int &num : arr) {
            if (num == 1) cntOnes += 1;
        }
        
        int maxGain = 0;
        int curr = 0;
        for (int &num : arr) {
            int val = (num == 1) ? -1 : 1;
            
            curr = max(val, curr + val);
            maxGain = max(maxGain, curr);
        }
        return cntOnes + maxGain;
    }
};