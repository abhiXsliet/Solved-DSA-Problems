// https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(MN * log(MN))
    // SC : O(M * N)
    int brute(int m, int n, int k) {
        vector<int> store;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                store.push_back(i * j);
            }
        }
        sort(begin(store), end(store));
        return store[k - 1];
    }
    
    int cntEleLessThanK(int m, int n, int mid) {
        int cnt = 0;
        for (int i = 1; i <= m; i ++) {
            cnt += min((mid / i), n);
        }
        return cnt;
    }
    
    // TC : O(M * log(M*N))
    // SC : O(1)
    int optimal(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cntEleLessThanK(m, n, mid) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
  public:
    int kthSmallest(int m, int n, int k) {
        // return brute(m, n, k);
        return optimal(m, n, k);
    }
};