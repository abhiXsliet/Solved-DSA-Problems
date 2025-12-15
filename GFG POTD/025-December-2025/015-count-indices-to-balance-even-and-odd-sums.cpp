// https://www.geeksforgeeks.org/problems/count-indices-to-balance-even-and-odd-sums/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        
        int totalEven = 0, totalOdd = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }

        int leftEven = 0, leftOdd = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // remove current element from total
            if(i % 2 == 0) totalEven -= arr[i];
            else totalOdd -= arr[i];

            // after deletion, right side parity flips
            int newEven = leftEven + totalOdd;
            int newOdd  = leftOdd + totalEven;

            if(newEven == newOdd)
                ans++;

            // add current element to left sums
            if(i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }
        return ans;
    }
};
