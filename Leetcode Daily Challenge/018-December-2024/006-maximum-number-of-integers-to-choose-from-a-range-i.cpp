// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(M))
    // SC : O(1)
    bool isAvailable(vector<int>& banned, int tar) {
        int m = banned.size();
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (banned[mid] == tar) {
                return true;
            } else if (banned[mid] > tar) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        return 0;
    }

    // TC : O(N) 
    // SC : O(M) Where M = size of banned array
    int brute(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(begin(banned), end(banned));
        int maxCount = 0;
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            if (!st.count(i) && sum + i <= maxSum) {
                sum += i;
                maxCount ++;
            }
        }
        return maxCount;
    }

    // TC : O(N * log(M)) Where M = size of banned array
    // SC : O(1)
    int optimal(vector<int>& banned, int n, int maxSum) {
        sort(begin(banned), end(banned));
        int maxCount = 0;
        int currSum  = 0;
        for (int i = 1; i <= n; i ++) {
            if (!isAvailable(banned, i) && currSum + i <= maxSum) {
                maxCount ++;
                currSum += i;
            }
        }
        return maxCount;
    }
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // return brute(banned, n, maxSum);

        return optimal(banned, n, maxSum);
    }
};