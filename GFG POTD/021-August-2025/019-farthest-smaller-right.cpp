// https://www.geeksforgeeks.org/problems/farthest-smaller-right/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(log(N))
    // SC : O(1)
    int getFarthestSmallest(vector<int> &suffix, int low, int high, int tar) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (suffix[mid] < tar) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
  public:
    // TC : O(N * log(N))
    // SC : O(N)
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix(n, arr[n - 1]);
        for (int i = n - 2; i >= 0; i --) {
            suffix[i] = min(suffix[i + 1], arr[i]);
        }
        
        vector<int> result(n, -1);
        for (int i = 0; i < n; i ++) {
            result[i] = getFarthestSmallest(suffix, i + 1, n - 1, arr[i]);
        }
        return result;
    }
};