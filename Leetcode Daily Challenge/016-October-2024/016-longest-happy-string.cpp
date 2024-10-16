// https://leetcode.com/problems/longest-happy-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(a + b + c)
    // SC : O(1)
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
       
        string res;
        while (!pq.empty()) {
            int currChCnt = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            
            if (res.length() >= 2 && res[res.length() - 1] == currChar 
                                  && res[res.length() - 2] == currChar) {
                // pop out next char with second highest freq cnt
                if (pq.empty()) break;

                int nextChCnt = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                res.push_back(nextChar);
                nextChCnt --;
                if (nextChCnt > 0) pq.push({nextChCnt, nextChar});

            } else {
                res.push_back(currChar);
                currChCnt --;
            }
            if (currChCnt > 0) pq.push({currChCnt, currChar});
        }
        return res;
    }
};