// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1) since map is used to store at most 2 distinct integers
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        
        unordered_map<int, int> mpp;
        int i = 0, j = 0, len = 0;
        while (j < n) {
            mpp[arr[j]] ++;
            while (i < j && mpp.size() > 2) {
                mpp[arr[i]] --;
                if (!mpp[arr[i]]) mpp.erase(arr[i]);
                i ++;
            }
            
            len = max(len, j - i + 1);
            
            j ++;
        }
        return len;
    }
};