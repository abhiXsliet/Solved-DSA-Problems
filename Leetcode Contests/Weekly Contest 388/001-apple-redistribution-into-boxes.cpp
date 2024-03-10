// https://leetcode.com/contest/weekly-contest-388/problems/apple-redistribution-into-boxes/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
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
};