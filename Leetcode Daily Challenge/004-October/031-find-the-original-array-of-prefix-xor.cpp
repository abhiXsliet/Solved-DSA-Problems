// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC = O(N)
    // SC = O(N) -> space to return the ans
    vector<int> solve_1(vector<int>& pref, int n) {
        vector<int> ans;
        ans.push_back(pref[0]);

        for (int i = 1; i < n; i++) {
            ans.push_back(pref[i] ^ pref[i-1]);
        }

        return ans;
    }

    // TC = O(N)
    // SC = O(1) -> modified the given array
    vector<int> solve_2(vector<int>& pref, int n) {

        for (int i = n - 1; i > 0; i--) {
            pref[i] = pref[i] ^ pref[i-1];
        }

        return pref;
    }
public:
    vector<int> findArray(vector<int>& pref) {
        // return solve_1(pref, pref.size());

        return solve_2(pref, pref.size());
    }
};