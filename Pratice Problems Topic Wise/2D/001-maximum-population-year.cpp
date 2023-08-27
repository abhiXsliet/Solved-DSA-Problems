// https://leetcode.com/problems/maximum-population-year/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        int n = logs.size();
        
        int first = INT_MAX;
        int last = INT_MIN;
        for(int i = 0; i < n; i++) {
            first = min(first, logs[i][0]);
            last = max(last, logs[i][1]);
        }
        int size = last - first + 1;

        vector<int> freq(size, 0);
        for(int i = 0; i < n; i++) {
            
            for(int year = logs[i][0]; year < logs[i][1]; year++) {
                freq[year - first] += 1;
            }

        }

        int maxi = INT_MIN;
        int ansYear = 0;
        for(int i = 0; i < size; i++) {
            if(freq[i] > maxi) {
                maxi = freq[i];
                ansYear = first + i;
            }
        }

        return ansYear;
    }
};