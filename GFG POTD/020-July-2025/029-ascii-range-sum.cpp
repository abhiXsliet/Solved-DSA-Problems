// https://www.geeksforgeeks.org/problems/ascii-range-sum/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    vector<int> asciirange(string& s) {
        int n = s.length();
        vector<pair<int, int>> firstOcc(26, {-1, -1}), lastOcc(26, {-1, -1});
        
        int asciiSum = 0;
        vector<int> uniques;
        for (int i = 0; i < n; i ++) {
            int idx = s[i] - 'a';
            asciiSum += s[i];
            if (firstOcc[idx].first == -1) {
                firstOcc[idx].first  = i;
                firstOcc[idx].second = asciiSum;
                uniques.push_back(idx);
            } else {
                lastOcc[idx].first  = i;
                lastOcc[idx].second = asciiSum;
            }
        }

        vector<int> result;
        for (int i = 0; i < uniques.size(); i++) {
            int idx =  uniques[i];
            int firstOccIdx = firstOcc[idx].first,  lastOccIdx = lastOcc[idx].first;
            int firstOccSum = firstOcc[idx].second, lastOccSum = lastOcc[idx].second;
            
            int resultantSum = lastOccSum - firstOccSum - (idx + 'a');
            if (resultantSum > 0) result.push_back(resultantSum);
        }
        return result;
    }
};