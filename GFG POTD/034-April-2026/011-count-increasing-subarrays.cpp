// https://www.geeksforgeeks.org/problems/count-increasing-subarrays5301/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        
        int ans = 0;
        int j = 0;
        for (int i = 1; i < n; i ++) {
            if (arr[i] > arr[i - 1]) {
                ans += (i - j);
            } else {
                j = i;
            }
        }
        return ans;
    }
};