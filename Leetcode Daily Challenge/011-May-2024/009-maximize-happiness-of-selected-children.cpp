// https://leetcode.com/problems/maximize-happiness-of-selected-children/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    
    // TC : O(N*log(N))
    // SC : O(1)
    long long maximumHappinessSum(vector<int>& h, int k) {
        ll maxHapp = 0;
        ll subVal  = 0; // subtraction val
        sort(rbegin(h), rend(h));
        int i = 0;
        while (k --) {
            if (h[i] > 0) {
                maxHapp += h[i] - subVal > 0 ? h[i] - subVal : 0;
                subVal ++;
                i ++;
            }
            else break;
        }
        return maxHapp;
    }
};