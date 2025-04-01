// https://leetcode.com/problems/solving-questions-with-brainpower/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    using ll = long long;
    ll t[100001];

    ll solve(vector<vector<int>> &ques, int i) {
        if (i >= n) return 0;

        if (t[i] != -1) return t[i];

        ll take = ques[i][0] + solve(ques, i + ques[i][1] + 1);
        ll notT = solve(ques, i + 1);

        return t[i] = max(take, notT);
    }

    // TC : O(N)
    // SC : O(N)
    ll top_down(vector<vector<int>> &questions) {
        memset(t, -1, sizeof(t));
        return solve(questions, 0);
    }

    // TC : O(N)
    // SC : O(N)
    ll bottom_up(vector<vector<int>> &ques) {
        memset(t, 0, sizeof(t));
        for (int i = n - 1; i >= 0; i --) {
            ll take = ques[i][0] + (((i + ques[i][1] + 1) < n) ? t[i + ques[i][1] + 1] : 0);
            ll notT = t[i + 1];
            t[i] = max(take, notT);
        }
        return t[0];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();

        // return top_down(questions);  
        return bottom_up(questions); 
    }
};