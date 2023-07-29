// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double isPossible(vector<int>& dist, int mid) {
        double total_time = 0.0;
        int n = dist.size();
        for(int i = 0; i < n-1; i++) {
            double time = (double)dist[i]/(double)mid;
            total_time += ceil(time);
        }

        total_time += (double)dist[n-1]/(double)mid;
        return total_time;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int start = 0;
        int end = 1e7;
        int result = -1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(isPossible(dist, mid) <= hour) {
                result = mid;
                end = mid - 1;

            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};