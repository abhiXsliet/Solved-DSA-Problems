// https://leetcode.com/problems/counting-bits/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * log(N))
    // SC = O(N) to store and return ans
    vector<int> solve_brute(int n) {
        vector<int> ans(n+1, 0);

        for (int i = 0; i <= n; i++) {
            int num = i;
            int cnt = 0;
            
            // at worst O(logN)
            while(num) {
                cnt += num%2;
                num /= 2;
            }
            ans[i] = cnt;
        }
        return ans;
    }

    // TC = O(N * log(N))
    // SC = O(N) to store and return ans
    vector<int> solve_stl(int n) {
        vector<int> result(n+1, 0);

        for(int i = 0; i <= n; i++) {
            result[i] = __builtin_popcount(i); // this function gives the no. of 1's
        }
        return result;
    }

    // TC = O(N)
    // SC = O(N) to store and return ans
    vector<int> solve_optimal(int n) {
        // ans[] to store the no.s of 1's from 0 to n
        vector<int> ans(n+1, 0);

        for (int i = 0; i <= n; i++) {
            ans[i] = ans[i/2] + i % 2;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {

        // return solve_brute(n);

        // return solve_stl(n);

        return solve_optimal(n);
    }
};