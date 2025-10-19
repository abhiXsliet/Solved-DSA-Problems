// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) +  b, end(s));
    }

    void solve(string curr, int a, int b, unordered_set<string> &visited, string &result) {
        if (visited.count(curr)) return;

        result = min(result, curr);
        visited.insert(curr);

        // add a on every odd index in s
        string temp = curr;
        for (int i = 1; i < temp.length(); i += 2) {
            temp[i] = (((temp[i] - '0') + a) % 10) + '0';
        }
        solve(temp, a, b, visited, result);

        // rotate the string curr by 'b'
        rotate(curr, b);
        solve(curr, a, b, visited, result);
    }

    // TC : O(10*N*N) 
    // SC : O(N*N)
    string approach_1(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);

        string result = s;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            result = min(result, curr);

            // add a on every odd index in s
            string temp = curr;
            for (int i = 1; i < temp.length(); i += 2) {
                temp[i] = (((temp[i] - '0') + a) % 10) + '0';
            }

            if (!visited.count(temp)) {
                visited.insert(temp);
                q.push(temp);
            }

            // rotate the string curr by 'b'
            rotate(curr, b);
            if (!visited.count(curr)) {
                visited.insert(curr);
                q.push(curr);
            }
        }
        return result;
    }

    // TC : O(10*N^2) total states
    // SC : O(N) recursive depth
    string approach_2(string s, int a, int b) {
        unordered_set<string> visited;
        string result = s;
        solve(s, a, b, visited, result);
        return result;
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        // return approach_1(s, a, b); // BFS
        return approach_2(s, a, b); // DFS
    }
};