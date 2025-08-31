// https://www.geeksforgeeks.org/problems/container-with-most-water0535/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        int i = 0, j = n - 1;
        int maxWaterCollected = 0;
        
        while (i < j) {
            int waterCollected = (j - i) * min(arr[i], arr[j]);
            maxWaterCollected  = max(maxWaterCollected, waterCollected);
            
            if (arr[i] < arr[j]) {
                i ++;
            } else {
                j --;
            }
        }
        
        return maxWaterCollected;
    }
};