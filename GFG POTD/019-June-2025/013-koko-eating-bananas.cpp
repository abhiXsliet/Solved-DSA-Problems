// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPossible(vector<int> &arr, int n, int tar, int k) {
        if (tar == 0) return false;
        
        int cntHrs = 0;
        for (int i = 0; i < n; i ++) {
            cntHrs += (arr[i] / tar);
            if (arr[i] % tar != 0) {
                cntHrs += 1;
            }
        }
        return cntHrs <= k;
    }
  public:
    // TC : O(N * log(max(arr))
    // SC : O(1)
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = *max_element(begin(arr), end(arr));
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, n, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};