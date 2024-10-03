// https://leetcode.com/problems/rank-transform-of-an-array/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> brute(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i ++) {
            vec.push_back({arr[i], i});
        }

        sort(begin(vec), end(vec));

        int rank = 1;
        int prev = vec[0].first;
        vector<int> result(n, rank);

        for (int i = 1; i < n; i ++) {
            int curr = vec[i].first;
            int idx  = vec[i].second;

            if (curr > prev) {
                rank ++;
                result[idx]  = rank;
            } else if (curr == prev) {
                result[idx]  = rank;
            }

            prev = curr;
        }

        return result;
    }
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        return brute(arr);  // SORTING AND RANKING
        // one slight modification : use map to store the rank of the uniques and assing those rank to the vector and return
    }
};