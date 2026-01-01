// https://leetcode.com/problems/plus-one/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int car = 1;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int last = digits[i];
            int sum  = last + car;
            ans.push_back(sum % 10);
            car = sum / 10;
        }
        if (car > 0) ans.push_back(car);
        reverse(begin(ans), end(ans));
        return ans;
    }
};