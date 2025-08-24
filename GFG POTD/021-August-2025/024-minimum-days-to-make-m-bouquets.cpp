// https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // is it possible to make 'm' bouquet in 'tar' days where a bouquets cost 'k' consecutive bloomed flowers
    bool isPossible(vector<int> &arr, int k, int m, int tar) {
        int bouquets = 0, consec = 0;
        for (int &days : arr) {
            if (days > tar) {
                consec = 0;
            } else {
                consec ++;
                if (consec == k) {
                    bouquets += 1;
                    consec = 0;
                }
            }
        }
        return bouquets >= m;
    }
  public:
    // TC : O(N * log(maxi - mini))
    // SC : O(1)
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int low  = *min_element(begin(arr), end(arr));
        int high = *max_element(begin(arr), end(arr));
        int ans  = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, m, mid)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
};