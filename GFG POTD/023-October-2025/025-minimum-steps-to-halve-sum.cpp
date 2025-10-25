// https://www.geeksforgeeks.org/problems/minimum-steps-to-halve-sum/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq;  // max-heap
        double totalSum = 0;
        
        for (int num : arr) {
            pq.push(num);
            totalSum += num;
        }
        
        double target = totalSum / 2.0;
        double currSum = totalSum;
        int operations = 0;
        
        while (currSum > target) {
            double top = pq.top();
            pq.pop();
            
            double half = top / 2.0;
            currSum -= half;   // reduction = half of top
            pq.push(half);
            
            operations++;
        }
        
        return operations;
    }
};