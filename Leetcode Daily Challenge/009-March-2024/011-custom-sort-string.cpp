// https://leetcode.com/problems/custom-sort-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M + N) Since Every char visited only once
    //               Where M = order.length() ~= 26(at worst) & N = s.length()
    // SC : O(26) + O(M + N) used by res at worst
    string solve_brute(string order, string s) {
        unordered_map<char, int> freq; // O(26)
        for (char& ch : s) {    // O(M)
            freq[ch] ++;
        }

        string res;
        for (char& ch : order) {    // O(26)
            if (freq.find(ch) != freq.end()) {
                while (freq[ch] > 0) {  // O(M) at worst a single char has M freq
                    res += ch;
                    freq[ch] --;
                }
            }
        }

        for (char& ch : s) {    // O(M)
            if (freq[ch] > 0) {
                res += ch;
            }
            freq[ch] --;
        }
        return res;
    }   

    // TC : O(N*log(N)) Where N = length of string s
    // SC : O(1)
    string solve_optimal(string order, string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < order.size(); i++) {
            freq[order[i] - 'a'] = i;
        }

        auto cmp = [&freq](char c1, char c2) {
            return freq[c1 - 'a'] < freq[c2 - 'a'];
        };

        sort(begin(s), end(s), cmp);

        return s;
    }   
public:
    string customSortString(string order, string s) {
        // return solve_brute(order, s);

        return solve_optimal(order, s);
    }
};