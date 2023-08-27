// https://leetcode.com/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array/



#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    // TC = O(N)
    // SC = O(N)
    long long solve_set(int n, int target) {
        ll ans = 0;
        unordered_set<ll> st;
        for(long long el = 1, cnt = 0 ; cnt < n; el++) {
            if(st.find(target - el) == st.end()) {
                st.insert(el);
                cnt++;
                ans += el;
            }
        }
        return ans;
    }

    // TC = O(N)
    // SC = O(N)
    long long solve_map(int n, int target) {
        ll el = 1;
        ll cnt = 0;
        ll ans = 0;
        unordered_map<ll, ll> mpp;
        while(1) {
            if (cnt == n) break;

            if(!mpp[target - el]) {
                mpp[el]++;
                cnt++;
                ans += el;
            }

            el++;
        }
        return ans;
    }
public:
    long long minimumPossibleSum(int n, int target) {

        // return solve_set(n, target);

        return solve_map(n, target);
    }
};