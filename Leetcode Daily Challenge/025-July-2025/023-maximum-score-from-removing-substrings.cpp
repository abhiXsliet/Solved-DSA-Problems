// https://leetcode.com/problems/maximum-score-from-removing-substrings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<string, int> removePairsWithoutStack(string &s, char first, char second, int pointPerPair) {
        int n = s.length();
        int i = 0, j = 0;
        int points = 0;
        while (j < n) {
            s[i] = s[j];    
            i ++;

            if (i - 2 >= 0 && s[i - 2] == first && s[i- 1] == second) {
                i -= 2;
                points += pointPerPair;
            }
            
            j ++;
        }

        string remaining = s.substr(0, i);

        return {remaining, points};
    }
    
    pair<string, int> removePairs(const string &s, char first, char second, int pointPerPair) {
        stack<char> stk;
        int points = 0;
        for (char ch : s) {
            if (!stk.empty() && stk.top() == first && ch == second) {
                stk.pop();
                points += pointPerPair;
            } else {
                stk.push(ch);
            }
        }

        string remaining;
        while (!stk.empty()) {
            remaining.push_back(stk.top());
            stk.pop();
        }
        reverse(begin(remaining), end(remaining));

        return {remaining, points};
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(string s, int x, int y) {
        int totalGain = 0;

        if (x > y) {
            // Remove "ab" first, then "ba"
            auto [remaining, pointsAB] = removePairs(s, 'a', 'b', x);
            auto [_, pointsBA]         = removePairs(remaining, 'b', 'a', y);
            totalGain = pointsAB + pointsBA;
        } else {
            // Remove "ba" first, then "ab"
            auto [remaining, pointsAB] = removePairs(s, 'b', 'a', y);
            auto [_, pointsBA]         = removePairs(remaining, 'a', 'b', x);
            totalGain = pointsAB + pointsBA;
        }

        return totalGain;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(string s, int x, int y) {
        int totalGain = 0;

        if (x > y) {
            // Remove "ab" first, then "ba"
            auto [remaining, pointsAB] = removePairsWithoutStack(s, 'a', 'b', x);
            auto [_, pointsBA]         = removePairsWithoutStack(remaining, 'b', 'a', y);
            totalGain = pointsAB + pointsBA;
        } else {
            // Remove "ba" first, then "ab"
            auto [remaining, pointsAB] = removePairsWithoutStack(s, 'b', 'a', y);
            auto [_, pointsBA]         = removePairsWithoutStack(remaining, 'a', 'b', x);
            totalGain = pointsAB + pointsBA;
        }

        return totalGain;
    }

    int maximumGain(string s, int x, int y) {
        // return approach_1(s, x, y);
        return approach_2(s, x, y);  // no exta space : i, j ptr => i writes while j reads
    }
};