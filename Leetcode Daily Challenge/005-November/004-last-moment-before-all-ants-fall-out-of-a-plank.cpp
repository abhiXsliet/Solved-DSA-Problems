// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;

        // <---------
        for (int& i : left) {
            result = max(result, i);
        }

        // --------->
        for (int& i : right) {
            result = max(result, n - i);
        }

        return result;
    }
};