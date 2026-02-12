// https://www.geeksforgeeks.org/problems/max-min-height--170647/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int isPossibleHeight(vector<int> &arr, int k, int w, int tar) {
        int n = arr.size();
        int cntDays = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            if (i > 0) diff[i] += diff[i - 1];
            
            if ((arr[i] + diff[i]) >= tar) continue;
            
            int need = tar - (arr[i] + diff[i]);
            diff[i] += need;
            if (i + w <= n) {
                diff[i + w] -= need;
            }
            
            cntDays += need;
            if (cntDays > k) return false;
        }
        return cntDays <= k;
    }
    
    int approach_1(vector<int> &arr, int k, int w) {
        int low  = *min_element(begin(arr), end(arr));
        int high = low + k;
        int ans  = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleHeight(arr, k, w, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        return approach_1(arr, k, w);
    }
};