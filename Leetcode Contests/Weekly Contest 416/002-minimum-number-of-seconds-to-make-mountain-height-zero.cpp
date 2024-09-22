// https://leetcode.com/contest/weekly-contest-416/problems/minimum-number-of-seconds-to-make-mountain-height-zero/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // BS on range of Height reduction
    // TC : log(maxSec)
    // SC : O(1)
    ll maxHeightReductionUsingBS(ll maxSec, ll wt) {
        // Find max height (mH) such that mH * (mH + 1) / 2 ≤ maxSec / wt
        // ( (mH * (mH + 1)) / 2 ) * wt <= maxSec
        ll low = 0;
        ll high = sqrt(2 * maxSec / wt);    // maxHeight can be reduced within 'wt' time
        ll ans = 0;  // maximum height can be reduced
        while (low <= high) {
            ll mid = low + (high - low) / 2;    // Height range
            ll reqT = mid * (mid + 1) / 2;
            if (reqT * wt <= maxSec) {
                ans = mid;
                low = mid + 1;  // try to increase the height
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // TC : O(1)
    // Find maximum height (mH) a worker can reduce in `maxSec` with a work rate of `wt` per unit height.
    ll maxHeightReduced(ll maxSec, ll wt) {
        // Given the equation: 1*wt + 2*wt + 3*wt + ... + mH*wt ≤ time,
        // we derive that mH(mH + 1)/2 ≤ time / wt. [taking common wt : wt*(1+2+3+...+mH) <= time]
        // This forms a quadratic equation: mH^2 + mH - 2C = 0, where C = time / wt.
        // Solving this quadratic equation gives the maximum mH a worker can achieve.
        ll C  = maxSec / wt;   
        ll mH = (-1 + sqrt(1 + 8*C)) / 2; // Solution to the quadratic equation
        return mH;
    }
    
    // This function checks if it's possible to reduce the mountain height `mountainH`
    // to 0 or below within `maxSec` using all worker's work rates provided in `workerTimes`.
    bool isPossible(ll maxSec, int mountainH, vector<int>& workerTimes) {
        // For each worker, determine how much height they can reduce within `maxSec`& sum it up. 
        // If the total reduction by all workers is >= mountain height, return true; otherwise, return false.
        
        ll totalHeightReduction = 0;

        for (int wt : workerTimes) {
            // ll heightReduction = maxHeightReduced(maxSec, wt); // Max height worker can reduce
            
            ll heightReduction = maxHeightReductionUsingBS(maxSec, wt);    // Max height worker can reduce using binary search
            
            totalHeightReduction += heightReduction;

            if (totalHeightReduction >= mountainH) {
                break;
            }
        }

        return totalHeightReduction >= mountainH;
    }

public:
    // TC : O(N * log(maxSec))     using (Quadratic Equation)
    // TC : O(N * log(maxSec) ^ 2) using (Binary search to find the maxHeight of each worker)
    // SC : O(1)
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        // Without Sort of Worker time works since binary search is on answer
        // but Sort it to optimize binary search  
        sort(begin(workerTimes), end(workerTimes)); 

        ll low = 0, high = 1e18, minReductionTime = 0;

        while (low <= high) {   // O(log(maxSec))
            ll mid = low + (high - low) / 2;

            if (isPossible(mid, mountainHeight, workerTimes)) { // O(N)
                minReductionTime = mid; 
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return minReductionTime;
    }
};