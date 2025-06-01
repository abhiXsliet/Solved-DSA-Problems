// https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1




#include <bits/stdc++.h>    
using namespace std;

class Solution {
  public:
    // TC : O(N^2)
    // SC : O(1)
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        
        int i1 = 0, j1 = 0;
        int i2 = n - 1, j2 = n - 1;
        int pairs = 0;
        while (i1 < n && i2 >= 0) {
            int sum = (mat1[i1][j1] + mat2[i2][j2]);
            
            if (sum <= x) {
                if (sum == x) {
                    pairs += 1;
                }
                j1 ++;
                if (j1 >= n) {
                    i1 += 1;
                    j1  = 0;
                }
            } else {
                j2 --;
                if (j2 < 0) {
                    j2  = n - 1;
                    i2 -= 1;
                }
            }
        }
        return pairs;
    }
};