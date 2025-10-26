// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<int>& arr) {
        int n = arr.size();
        //step-1 : create a minHeap using priority queue
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        //step-2 : push all elements into the priority queue
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        //step-3 : calculate minimum cost
        long long cost = 0;
        
        while(pq.size() > 1){
            
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }
};