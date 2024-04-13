// https://leetcode.com/problems/gas-station/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*N)
    // SC : O(1)
    int solve_brute(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (gas[i] < cost[i]) continue;

            int j = (i + 1) % n;
            int currGas = gas[i] - cost[i];
            while(j != i) {
                currGas += gas[j];
                if (currGas < cost[j])
                    break;
                currGas -= cost[j];
                j = (j + 1) % n;
            }
            if (i == j) return i;
        }
        return -1;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_optimal(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();

        int totalGas  = accumulate(begin(gas) , end(gas), 0);
        int totalCost = accumulate(begin(cost), end(cost), 0);

        if (totalGas < totalCost) return -1;

        totalGas   = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i] - cost[i];

            if (totalGas < 0) {
                result   = i + 1;
                totalGas = 0;
            }
        }
        return result;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // return solve_brute(gas, cost);

        return solve_optimal(gas, cost);
    }
};