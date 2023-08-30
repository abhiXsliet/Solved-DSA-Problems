// https://leetcode.com/problems/minimum-penalty-for-a-shop/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N^2) -> TLE
    // SC = O(1)
    int solve_brute(string customers) {
        int n = customers.length();
        int minPenalty = INT_MAX;
        int minHour    = INT_MAX;

        for (int i = 0; i < n; i++) {
            int penalty = 0;
            // 1-Case : i-1 to 0 -> find penalty when shop was open & we had 'N'
            for (int j = i-1; j >= 0; j--) 
                if (customers[j] == 'N') 
                    penalty += 1;

            // 2-Case : i to n -> find penalty when shop was closed & we had 'Y'
            for (int j = i; j < n; j++) 
                if (customers[j] == 'Y') 
                    penalty += 1;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                minHour = i;
            }
        }

        // 3-Case : including the nth hour 
        // 0 till n -> if we found N then penalty
        int nthHourPenalty = 0;
        for(int i = 0; i <= n; i++) {
            if (customers[i] == 'N')
                nthHourPenalty += 1;
        }

        if (nthHourPenalty < minPenalty) {
            minPenalty = nthHourPenalty;
            minHour = n;
        }

        return minHour;
    }

    // TC = O(N)
    // SC = O(N)
    int solve_better(string customers) {
        int n = customers.length();
        vector<int> prefix_N(n+1, 0);
        prefix_N[0] = 0;

        vector<int> suffix_Y(n+1, 0);
        suffix_Y[n] = 0; 
        
        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'N') {
                prefix_N[i] = prefix_N[i-1] + 1;
            } else {
                prefix_N[i] = prefix_N[i-1];
            }
        }

        for(int i = n-1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                suffix_Y[i] = suffix_Y[i+1] + 1;
            } else {
                suffix_Y[i] = suffix_Y[i+1];
            }
        }

        int minPenalty = INT_MAX;
        int minHour    = INT_MAX;

        for (int i = 0; i <= n; i++) {
            int currPenalty = prefix_N[i] + suffix_Y[i];
            
            if (currPenalty < minPenalty) {
                minPenalty = currPenalty;
                minHour = i;
            }
        }

        return minHour;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_optimal(string customers) {
        int n = customers.length();

        int minHour = 0;
        int penalty = count(customers.begin(), customers.end(), 'Y');

        int minPenalty = penalty;

        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') 
                penalty--;
            else 
                penalty++;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                minHour = i+1;
            }
        }
        return minHour;
    }

    // TC = O(N)
    // SC = O(1)
    int solve_greedy(string customers) {
        int penalty = 0;       
        int minPenalty = penalty, minHour = 0;

        for(int i = 1; i <= customers.length(); i++) {
            
            if(customers[i-1] == 'Y') penalty--;
            else penalty++;

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHour = i;
            }
        }
        return minHour;
    }
public:
    int bestClosingTime(string customers) {
        
        // return solve_brute(customers);

        // return solve_better(customers);

        // return solve_optimal(customers);

        return solve_greedy(customers);
    }
};