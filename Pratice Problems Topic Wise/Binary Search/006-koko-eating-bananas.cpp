// https://leetcode.com/problems/koko-eating-bananas/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossibleToEat(int mid, vector<int>& piles, int h) {
        long long hour = 0;
        for (int& pile : piles) {
            hour += pile / mid;
            if (pile % mid) {
                hour ++;
            }
        }
        return hour <= h;
    }
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1, high = *max_element(begin(piles), end(piles));
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossibleToEat(mid, piles, h)) {
                ans  = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};