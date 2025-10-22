// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i <= k; i ++) {
            pq.push(arr[i]);
        }
        
        int idx = 0;
        for (int i = k + 1; i < n; i ++) {
            arr[idx ++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while (!pq.empty()) {
            arr[idx ++] = pq.top();
            pq.pop();
        }
    }
};