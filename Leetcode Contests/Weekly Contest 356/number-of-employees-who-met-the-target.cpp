// https://leetcode.com/contest/weekly-contest-356/problems/number-of-employees-who-met-the-target/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n = hours.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(hours[i] >= target) cnt++;
        }
        return cnt;
    }
};