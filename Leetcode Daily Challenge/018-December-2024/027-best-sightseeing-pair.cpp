// https://leetcode.com/problems/best-sightseeing-pair/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        int maxScore = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int val = nums[i] + nums[j] + (i - j);
                maxScore = max(maxScore, val);
            }
        }
        return maxScore;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int better(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i ++) {
            pq.push({nums[i] - i, i});
        }
        int maxScore = 0;
        for (int i = 0; i < n; i ++) {
            while (!pq.empty() && pq.top().second <= i)
                pq.pop();
                
            if (!pq.empty()) {
                int val = pq.top().first;
                maxScore = max(maxScore, nums[i] + i + val);
            }
        }
        return maxScore;
    }

    // TC : O(N)
    // SC : O(N)
    int optimal_1(vector<int>& values) {
        int n = values.size();
        int val = values[n - 1] - (n - 1);
        vector<int> suffixMax(n, val);
        for (int i = n - 2; i >= 0; i --) {
            suffixMax[i] = max(values[i] - i, suffixMax[i + 1]); 
        }
        int maxScore = 0;
        for (int i = 0; i < n - 1; i ++) {
            maxScore = max(maxScore, values[i] + i + suffixMax[i + 1]);
        }
        return maxScore;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal_2(vector<int>& values) {
        int n = values.size();
        int maxScore = 0;
        int maxVal = values[0] + 0;
        for (int i = 1; i < n; i ++) {
            maxScore = max(maxScore, maxVal + values[i] - i); 
            maxVal   = max(maxVal, values[i] + i);
        }
        return maxScore;
    }
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // return brute(values);    // use two for loops
        // return better(values);   // precalc (nums[j] - j) & do (nums[i] + i) on the go
        // return optimal_1(values);// suffix array of maxValue of (nums[j] - j);
        return optimal_2(values);   // No Extra Space
    }
};