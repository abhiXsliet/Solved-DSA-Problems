// https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size(), m = arr2.size();
        int i = 0, j = m - 1;
        int minDiff = INT_MAX;
        vector<int> result(2, 0);
        
        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = arr1[i];
                result[1] = arr2[j];
            }
            
            if (sum > x) j --;
            else i ++;
        }
        
        return result;
    }
};