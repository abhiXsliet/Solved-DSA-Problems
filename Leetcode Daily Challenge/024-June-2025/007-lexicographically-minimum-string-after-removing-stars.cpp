// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<char, int> P;

    // TC : O(N * log(N))
    // SC : O(N)
    string clearStars(string s) {
        int n = s.length();

        auto cmp = [&](P p1, P p2) {
            if (p1.first == p2.first) {
                return p2.second > p1.second;   // higher index first
            }
            return p1.first > p2.first; // lexiographically smaller char first
        };
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < n; i ++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else if (!pq.empty()){
                int idx = pq.top().second;
                s[idx] = '*';
                pq.pop();
            }
        }
        string result;
        for (char &ch : s) {
            if (ch != '*') {
                result += ch;
            }
        }
        return result;
    }
};