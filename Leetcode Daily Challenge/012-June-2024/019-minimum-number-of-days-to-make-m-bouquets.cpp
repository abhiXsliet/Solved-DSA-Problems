// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    bool isPossibleToMakeBouquets(vector<int>&bloomDay, int m, int k, int mid) {
        // is it possible to make bouquets in 'mid' no. of days?
        int n = bloomDay.size();

        int cntDays = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                cntDays += 1;
                if (cntDays == k) {
                    cntDays = 0;
                    m      -= 1;
                    if (m == 0) break;
                }
            } else {
                cntDays = 0;    // Consecutive Days Cnt becomes 0
            }
        }
        return m == 0;
    }
public:
    // TC : O(N*log(max_element))
    // SC : O(1)
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long)m*k) return -1;

        int low = 1, high = *max_element(begin(bloomDay), end(bloomDay));
        int minDays = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isPossibleToMakeBouquets(bloomDay, m, k, mid)) {
                minDays  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return minDays;
    }
};