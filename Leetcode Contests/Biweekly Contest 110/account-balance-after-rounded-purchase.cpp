// https://leetcode.com/contest/biweekly-contest-110/problems/account-balance-after-rounded-purchase/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int n) {
        int a = (n/10) * 10;
        int b = a + 10;
        
        if(n - a >= b - n) {
            return abs(100 - b);
        } else {
            return abs(100 - a);
        }
    }
};