// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<char, int> P;

    // TC : O(N * N)
    // SC : O(N)
    string brute(string& s, int n) {
        vector<int> indices;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '*') {
                indices.push_back(i);
            }
        }

        int decrement = 0;
        for (int i = 0; i < indices.size(); i ++) {
            indices[i] -= decrement;
            decrement  += 2;
        }

        for (int i = 0; i < indices.size(); i ++) {
            // finding smallest char left of *
            vector<int> smallestCharIdx(26, -1);
            
            for (int j = indices[i] - 1; j >= 0; j --) {
                int idx = s[j] - 'a';
                if (smallestCharIdx[idx] == -1) 
                    smallestCharIdx[idx] = j;
            }

            // erase *
            s.erase(indices[i], 1);

            // erase the first smallest char to the left of star
            for (int j = 0; j < 26; j ++) {
                if (smallestCharIdx[j] != -1) {
                    s.erase(smallestCharIdx[j], 1);
                    break;
                }
            }
        }

        return s;
    }

    struct compare {
        bool operator()(P &p1, P &p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    // TC : O(N*log(N))
    // SC : O(N)
    string optimal(string& s, int n) {
        auto cmp = [&](P &p1, P &p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        };

        // pq is used to store the last smallest seen char
        // priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);     // Way-1 of declaring pq

        priority_queue<P, vector<P>, compare> pq;               // Way-2 of declaring pq

        for (int i = 0; i < n; i ++) {
            if (s[i] == '*') {
                P topEl = pq.top();
                pq.pop();
                s[topEl.second] = '*';
            } else {
                pq.push({s[i], i});
            }
        }

        string result;
        for (int i = 0; i < n; i ++) {
            if (s[i] != '*') {
                result += s[i];
            }
        }
        return result;
    }
public:
    string clearStars(string s) {
        // return brute(s, s.length());

        return optimal(s, s.length());
    }
};