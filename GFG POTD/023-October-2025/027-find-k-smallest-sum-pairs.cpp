// https://www.geeksforgeeks.org/problems/find-k-smallest-sum-pairs/1/




#include <bits/stdc++.h>    
using namespace std;

class Solution {
  public:
    // TC : O(K*log(K))
    // SC : O(K)
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> result;
        if (arr1.empty() || arr2.empty()) return result;
        
        using T = tuple<long long, int, int>; // {sum, i, j}
        priority_queue<T, vector<T>, greater<T>> pq;
        set<pair<int,int>> visited;
        
        pq.push({(long long)arr1[0] + arr2[0], 0, 0});
        visited.insert({0, 0});
        
        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            result.push_back({arr1[i], arr2[j]});
            
            if (j + 1 < arr2.size() && !visited.count({i, j + 1})) {
                pq.push({(long long)arr1[i] + arr2[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
            if (i + 1 < arr1.size() && !visited.count({i + 1, j})) {
                pq.push({(long long)arr1[i + 1] + arr2[j], i + 1, j});
                visited.insert({i + 1, j});
            }
        }
        
        return result;
    }
};