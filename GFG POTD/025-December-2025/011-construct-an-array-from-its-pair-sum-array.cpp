// https://www.geeksforgeeks.org/problems/construct-an-array-from-its-pair-sum-array/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int m = arr.size(); // m = n * (n - 1) / 2
        
        int n = (1 + sqrt(1 + 8LL * m)) / 2;

        vector<int> res(n);
        
        int s1 = arr[0];
        int s2 = arr[1];
        int s3 = arr[n - 1];
        
        res[0] = (s1 + s2 - s3) / 2;
        
        for (int i = 1; i < n; i ++) {
            res[i] = arr[i - 1] - res[0];
        }
        
        return res;
    }
};