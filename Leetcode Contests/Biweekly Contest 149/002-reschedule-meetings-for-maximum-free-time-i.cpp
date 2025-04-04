// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxInKSizeWindow(vector<int>& arr, int k) {
        int n = arr.size(), i = 0, j = 0;
        if (k > n) return accumulate(begin(arr), end(arr), 0);
        int maxVal = 0;
        int sum = 0;
        while (j < n) {
            sum += arr[j];
            if (j - i + 1 == k) {
                maxVal = max(maxVal, sum);
                sum -= arr[i];
                i ++;
            }
            j ++;
        }
        return maxVal;
    }
public:
    // TC : O(N)
    // SC : O(N)
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> freeTime(n + 1, 0);
        int startT = 0;
        for (int i = 0; i < n; i ++) {
            freeTime[i] = startTime[i] - startT;
            startT = endTime[i];
        }
        if (eventTime > startT) {
            freeTime[n] = eventTime - startT; 
        }

        return maxInKSizeWindow(freeTime, k + 1);
    }
};