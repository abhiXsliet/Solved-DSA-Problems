// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& arr, int shops, int x) {
        int stores = 0;
        for (int i = 0; i < arr.size(); i ++) {
            stores += (arr[i] + x - 1) / x;
            if (stores > shops) return false;
        }
        return true;
    }
public:
    // TC : O(M * Log(M)) Where M = quantities length
    // SC : O(1)
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(begin(quantities), end(quantities));
        int res = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(quantities, n, mid)) {
                res  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};