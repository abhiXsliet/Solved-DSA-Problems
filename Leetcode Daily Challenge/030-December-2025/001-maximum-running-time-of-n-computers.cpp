// https://leetcode.com/problems/maximum-running-time-of-n-computers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& batteries, long long mid, int n) {
        long long sum = 0;
        long long required_min = mid * n;

        for(int i = 0; i < batteries.size(); i++) {
            sum += min((long long)batteries[i], mid);
            
            if(sum >= required_min) return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long result = 0;
        long long left = *min_element(batteries.begin(), batteries.end());

        long long total_sum = 0;
        for(auto& i : batteries)
            total_sum += i;
            
        long long right = total_sum / n;

        while(left <= right) {
            long long mid = left + (right - left)/2;
            
            if(isPossible(batteries, mid, n)) {
                result = mid;
                left = mid+1;

            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};