// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    using P = pair<int, int>;
    
    // TC : O(N log(N) + K log(K)) where N = size of a, b and K = k
    // SC : O(K) for priority queue and set
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        sort(begin(a), end(a));
        sort(begin(b), end(b));
        
        vector<int> result;
        priority_queue<pair<int, P>> pq;    // {sum, {i, j}}
        set<P> visited;
        int i = n - 1, j = n - 1;
        pq.push({a[i] + b[j], {i , j}});
        visited.insert({i, j});
        
        while (result.size() < k) {
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            result.push_back(sum);
            
            if (i >= 0 && !visited.count({i - 1, j})) { 
                pq.push({a[i - 1] + b[j], {i - 1 , j}});
                visited.insert({i - 1, j});
            }
            if (j >= 0 && !visited.count({i, j - 1})) {
                pq.push({a[i] + b[j - 1], {i, j - 1}});
                visited.insert({i, j - 1});
            }
        }
        
        return result;
    }
};