// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/



#include <bits/stdc++.h>   
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N*log(N))
    // SC : O(1)
    ll better(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill), end(skill));

        ll scoreOfTeam = skill[0] + skill[n - 1];
        ll chemistry = 0;
        int i = 0, j = n - 1;

        while (i < j) {
            ll sum = skill[i] + skill[j];

            if (sum != scoreOfTeam) 
                return -1;

            chemistry += (skill[i] * skill[j]);
            i ++;
            j --;
        }

        return chemistry;
    }

    // TC : O(N)
    // SC : O(1000)
    ll optimal_1(vector<int>& skill) {
        int n = skill.size();

        int maxi = *max_element(begin(skill), end(skill));
        ll totScore = 0;
        vector<int> freq(maxi + 1, 0);
        for (int& val : skill) {
            totScore += val;
            freq[val] ++;
        }
        
        int teamCnt  = n / 2;
        ll teamScore = totScore / teamCnt;

        if (totScore % teamCnt != 0) 
            return -1;

        ll chemistry = 0;
        for (int i = 0; i < n; i ++) {
            int reqScore = (teamScore - skill[i]);

            if (freq[reqScore] <= 0) 
                return -1;

            chemistry += (skill[i] * reqScore);
            freq[reqScore] --;
        }
        return chemistry/2; // dividing by 2 to skip duplicates
    }

    // TC : O(N)
    // SC : O(N) ~= O(1000)
    ll optimal_2(vector<int>& skill) {
        int n = skill.size();

        int teamCnt  = n / 2;
        ll totScore  = accumulate(begin(skill), end(skill), 0LL);
        ll teamScore = totScore / teamCnt;

        ll result = 0;
        unordered_map<int, int> mpp;    // {ele, cnt}

        for (int &val : skill) {
            int req = teamScore - val;
            if (mpp.count(req)) {
                result += (val * req);
                mpp[req] --;
                if (mpp[req] == 0) {
                    mpp.erase(req);
                }
                continue;
            }
            mpp[val] ++;
        }

        return mpp.size() == 0 ? result : -1;
    }
    ll dividePlayers(vector<int>& skill) {
        // Brute : Try all pairs

        // return better(skill);       // Sorting

        // return optimal_1(skill);    // Counting Sort

        return optimal_2(skill);    // HashMap
    }
};