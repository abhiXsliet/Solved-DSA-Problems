// https://leetcode.com/problems/calculate-money-in-leetcode-bank/



#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    // TC = O(N)
    // SC = O(1)
    int solve_brute(int n) {
        int ans = 0;
        int val = 1;
        int new_val = val + 1;
        int day = 1;
        while(n != 0) {
            if (day > 7) {
                val = new_val;
                new_val ++;
                day = 1;
            }
            ans += val;
            day++;
            val++;
            n--;
        }
        return ans;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_better(int n) {
        int result = 0;
        int monday_money = 1; 
        while (n > 0) {
            int money = monday_money;
            for (int i = 1; i <= min(n, 7); i++) {
                result += money;
                money++;
            }
            monday_money++;
            n = (n - 7);
        }
        return result;
    }

    // TC = O(1)
    // SC = O(1)
    // Intitution -> AP Approach
    int solve_optimal(int n) {
        int total_terms = n / 7;
        // sum of all deposited money from mondey to sunday
        int first_term  = 28;  
        // nth term = a + (n - 1) * d
        int last_term   = first_term + (total_terms - 1) * 7; 
        // sum of AP = n * (a + l) / 2;
        int result      = total_terms * (first_term + last_term) / 2;

        // remaining week days money
        int start_money = total_terms + 1;

        for (int i = 1; i <= n % 7; i++) {
            result += start_money;
            start_money++;
        }

        return result;
    }
public:
    int totalMoney(int n) {
        // return solve_brute(n);

        // return solve_better(n);

        return solve_optimal(n);
    }
};