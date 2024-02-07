// https://leetcode.com/problems/sort-characters-by-frequency/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N + K*log(K))
    // SC : O(K) where K = No. Of Unique Chars
    string solve_approach_1(string& s, int n) {
        unordered_map<char, int> mpp;
        for (char& ch : s) {
            mpp[ch] ++;
        }

        auto Compare = [&](pair<int, char> a, pair<int, char> b) {
            if (a.first == b.first) return b.second < b.first;
            return a.first < b.first;
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(Compare)> pq(Compare);

        for (auto& it : mpp) {
            pq.push({it.second, it.first});
        }

        string result;

        while(!pq.empty()) {
            int charNo = pq.top().first;
            char ch    = pq.top().second;
            for (int i = 0; i < charNo; i++) {
                result += ch;
            }
            pq.pop();
        }
        
        return result;        
    }

    // TC : O(N) + O(K*log(K))
    // SC : O(80) ~= O(1)
    string solve_approach_2(string& s, int n) {
        // store char and its count in freq
        vector<pair<int, char>> freq(80, {0, 0});
        for (char& ch : s) {
            freq[ch - '0'].first ++;
            freq[ch - '0'].second = ch;
        }
        
        auto cmp = [&](pair<int, char> a, pair<int, char> b) {
            if (a == b) return a.second < b.second;
            return a.first > b.first;
        };

        sort(begin(freq), end(freq), cmp);

        string result = "";

        for (auto& it : freq) {
            int charCnt = it.first;
            char ch     = it.second;
            for (int j = 0; j < charCnt; j++) {
                result += ch;
            }
        }
        
        return result;        
    }

    // TC : O(N) + O(K*log(K)) where k = no. of unique chars
    // SC : O(K)
    // Modify the given string
    string solve_approach_3(string& s, int n) {
        unordered_map<char, int> mpp;

        for (char& ch : s) {
            mpp[ch]++;
        }

        auto cmp = [&](char a, char b) {
            // If frequencies are different, sort by frequency in descending order
            if (mpp[a] != mpp[b]) {
                return mpp[a] > mpp[b];
            }
            // If frequencies are the same, sort by character in ascending order
            return a < b;
        };

        sort(begin(s), end(s), cmp);

        return s;
    }
public:
    string frequencySort(string s) {
        // return solve_approach_1(s, s.length());

        // return solve_approach_2(s, s.length());

        return solve_approach_3(s, s.length());
    }
};