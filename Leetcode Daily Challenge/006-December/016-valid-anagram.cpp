// https://leetcode.com/problems/valid-anagram/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(max(NlogN, MlogM))
    // SC : O(1)
    bool solve_brute(string& s, string& t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));

        return s == t;
    }

    // TC : O(max(N, M))
    // SC : O(N) ~ O(1)
    bool solve_better(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> mpp;

        if (n != m)
            return false;

        for (char ch : s) {
            mpp[ch]++;
        }

        for (char ch : t) {
            if (mpp[ch] > 0)
                mpp[ch]--;
            else 
                return false;
        }

        return true;
    }

    // TC : O(max(N, M))
    // SC : O(26) ~ O(1)
    bool solve_optimal(string& s, string& t) {
        // vector size-128 is enough to cover both the lowercase and unicode chars
        vector<int> store(26, 0);
        
        for (char ch : s) {
            store[ch - 'a']++;
        }

        for (char ch : t) {
            store[ch - 'a']--;
        }

        // check if the freq of all chars has become zero
        bool checkZeros = all_of(begin(store), end(store), [](int element) {
            return element == 0;
        });

        return checkZeros;
    }
public:
    bool isAnagram(string s, string t) {
        // return solve_brute(s, t);

        // return solve_better(s, t);

        return solve_optimal(s, t);
    }
};