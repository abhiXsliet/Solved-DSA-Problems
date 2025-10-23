// https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    typedef pair<int, pair<int, int>> P;
    
    int getEuclideanDist(int x, int y) {
        return x*x + y*y;  // no sqrt
    }
    
    // O(N log K)
    vector<vector<int>> approach_2(vector<vector<int>>& points, int k) {
        priority_queue<P> pq; 
        for (auto &point : points) {
            int dist = getEuclideanDist(point[0], point[1]);
            pq.push({dist, {point[0], point[1]}});
            if (pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return result;
    }
    
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return approach_2(points, k);
    }
};