// https://leetcode.com/problems/apple-redistribution-into-boxes/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(rbegin(capacity), rend(capacity));
        int totApples = accumulate(begin(apple), end(apple), 0);
        int cnt = 0;
        for (int cap : capacity) {
            if (totApples > 0) {
                cnt ++;
                totApples -= cap;
            }
            if (totApples <= 0) break;
        }
        return cnt;
    }
};