// https://www.geeksforgeeks.org/problems/difference-check/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    const int TOTAL_SEC = 86400;
    
    int getTotalSeconds (string &str) {
        int h = stoi(str.substr(0, 2));
        int m = stoi(str.substr(3, 2));
        int s = stoi(str.substr(6, 2));
        
        return (3600 * h + 60 * m + s);
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    int approach_1(vector<string> &arr) {
        int n = arr.size();
        vector<int> seconds;
        
        for (string &s : arr) {
            seconds.push_back(getTotalSeconds(s));
        }
        
        sort(begin(seconds), end(seconds));
        
        int minDiff = INT_MAX;
        
        for (int i = 1; i < n; i ++) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }
        
        int circularDiff = TOTAL_SEC - (seconds[n - 1] - seconds[0]);
        
        return min(minDiff, circularDiff);
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<string> &arr) {
        int n = arr.size();
        bool timeSeen[TOTAL_SEC] = {false};
        
        for (int i = 0; i < n; i ++) {
            int seconds = getTotalSeconds(arr[i]);
            if (timeSeen[seconds]) return 0;    // already seen time : so diff is 0
            timeSeen[seconds] = true;
        }
        
        int minDiff = INT_MAX, first = -1, prev = -1;
        
        for (int i = 0; i < TOTAL_SEC; i ++) {
            if (timeSeen[i]) {
                if (first == -1) first = i;
                if (prev  != -1) minDiff = min(minDiff, i - prev);
                prev = i;
            }
        }
        
        minDiff = min(minDiff, TOTAL_SEC - (prev - first));
        
        return minDiff;
    }
  public:
    int minDifference(vector<string> &arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
};