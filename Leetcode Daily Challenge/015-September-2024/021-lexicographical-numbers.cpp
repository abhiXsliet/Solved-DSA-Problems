// https://leetcode.com/problems/lexicographical-numbers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> brute(int n) {
        vector<int> res(n, 0);
        for (int i = 0; i < n; i ++) {
            res[i] = (i + 1);
        }

        auto cmp = [&](int a, int b) {
            return to_string(a) < to_string(b);
        };

        sort(begin(res), end(res), cmp);
        return res;
    }

    // TC : O(N) for Visiting every no. once
    // SC : O(no. of digits in N) ~= O(log(N) base 10) Recursive Stack Space 
    void solve(int currN, int limit, vector<int>& res) {
        if (currN > limit) return;

        res.push_back(currN);

        for (int append = 0; append <= 9; append ++) {
            int newN = (currN * 10) + append;
            if (newN > limit) return;
            solve(newN, limit, res);
        }
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> optimal(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i ++) {
            solve(i, n, res);
        }
        return res;
    }
public:
    vector<int> lexicalOrder(int n) {
        // return brute(n);    // sort() fn

        return optimal(n);
    }
};