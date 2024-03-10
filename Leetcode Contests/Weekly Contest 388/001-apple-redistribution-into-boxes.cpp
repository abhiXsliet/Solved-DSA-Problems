// https://leetcode.com/contest/weekly-contest-388/problems/apple-redistribution-into-boxes/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve_approach_1(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int sum = accumulate(begin(apple), end(apple), 0);
        int cnt = 0;
        for (int cap : capacity) {
            if (sum > 0) {
                cnt++;
                sum -= cap;
            }
            if (sum <= 0) break;
        }
        return cnt;
    }
    
    int solve_approach_2(vector<int>& apple, vector<int>& capacity) {
        priority_queue<int> pq;
        for (int cap : capacity) {
            pq.push(cap);
        }
        int sum = accumulate(begin(apple), end(apple), 0);
        int cnt = 0;
        while (!pq.empty()) {
            if (sum > 0) {
                cnt ++;
                int el = pq.top();
                sum -= el; pq.pop();
            }
            if (sum <= 0) break;
        }
        return cnt;
    }
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // return solve_approach_1(apple, capacity);
        
        return solve_approach_2(apple, capacity);
    }
};
