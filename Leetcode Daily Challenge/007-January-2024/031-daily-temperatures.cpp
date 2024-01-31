// https://leetcode.com/problems/daily-temperatures/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(1)
    vector<int> solve_brute(vector<int>& temp, int n) {
        vector<int> result;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i != j && temp[j] > temp[i]) {
                    result.push_back(j - i);
                    break;
                }
                if (j == n - 1) {
                    result.push_back(0);
                }
            }
        }

        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> solve_optimal_1(vector<int>& temp, int n) {
        unordered_map<int, int> mpp;
        stack<pair<int, int>> stk;

        for (int i = 0; i < n; i++) { 
            while (!stk.empty() && stk.top().first < temp[i]) {
                mpp[stk.top().second] = i;
                stk.pop();
            }
            stk.push({temp[i], i});
        }

        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (mpp.find(i) != mpp.end()) {
                result.push_back(mpp[i] - i);
            }
            else result.push_back(0);
        }

        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> solve_optimal_2(vector<int>& temp, int n) {
        vector<int> result(n);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) { 
            while(!stk.empty() && temp[stk.top()] <= temp[i]) {
                stk.pop();
            }

            if (stk.empty()) {
                result[i] = 0;
            }
            else {
                result[i] = stk.top() - i;
            }
            stk.push(i);
        }

        return result;
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // return solve_brute(temperatures, temperatures.size());

        // return solve_optimal_1(temperatures, temperatures.size());

        return solve_optimal_2(temperatures, temperatures.size());
    }
};