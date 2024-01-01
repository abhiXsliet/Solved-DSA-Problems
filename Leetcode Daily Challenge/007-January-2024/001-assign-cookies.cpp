// https://leetcode.com/problems/assign-cookies/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int solve_approach_1(vector<int>& g, vector<int>& s) {
        int j = 0;
        int cnt = 0;

        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());

        int sizeS = s.size();
        int sizeG = g.size();
        
        for(int i=0; i<sizeG; i++) {
            if(j < sizeS && g[i] <= s[j]) {
                cnt++;
                j++;
            }
        }
        return cnt;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_approach_2(vector<int>& g, vector<int>& s) {
        int i = 0;
        int j = 0;
        
        int cnt = 0;
        int n = g.size();
        int m = s.size();
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(i<n && j<m) {
            if(s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // return solve_approach_1(g, s);

        return solve_approach_2(g, s);
    }
};