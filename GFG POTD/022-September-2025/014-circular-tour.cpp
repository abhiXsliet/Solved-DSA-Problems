// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int balance = 0;
        
        for (int i = 0; i < n; i ++) {
            balance += (gas[i] - cost[i]);
        }
        
        if (balance < 0) return -1;
        
        int curr_bal = 0, startPt = 0;
        for (int i = 0; i < n; i ++) {
            curr_bal += (gas[i] - cost[i]);
            if (curr_bal < 0) {
                startPt = i + 1;
                curr_bal = 0;
            }
        }
        return startPt;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int deficit = 0, curr_bal = 0, startPt = 0;
        for (int i = 0; i < n; i ++) {
            curr_bal += (gas[i] - cost[i]);
            if (curr_bal < 0) {
                deficit += curr_bal;
                startPt  = i + 1;
                curr_bal = 0;
            }
        }
        return (curr_bal + deficit >= 0) ? startPt : -1;
    }
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // return approach_1(gas, cost);    
        return approach_2(gas, cost);    // one pass
    }
};