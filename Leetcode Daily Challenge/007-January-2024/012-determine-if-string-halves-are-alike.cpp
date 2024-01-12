// https://leetcode.com/problems/determine-if-string-halves-are-alike/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // TC : O(N)
    // SC : O(N) -> building string
    bool solve_brute(string& s, int n) {
        int idx1 = n/2;
        
        string str1;
        for (int i = 0; i < idx1; i++) {
            str1 += s[i];
        }

        string str2;
        for (int i = idx1; i < n; i++) {
            str2 += s[i];
        }

        int cnt1 = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (isVowel(str1[i])) cnt1++;
        }

        int cnt2 = 0;
        for (int i = 0; i < str2.length(); i++) {
            if (isVowel(str2[i])) cnt2++;
        }

        return cnt1 == cnt2;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_optimal_1(string& s, int n) {
        int cnt1(0), cnt2(0);
        int i(0), j(n - 1);
        while (i < j) {
            if (isVowel(s[i])) cnt1 ++;
            if (isVowel(s[j])) cnt2 ++;
            i++, j--;
        }
        return cnt1 == cnt2;
    }

    // TC : O(N)
    // SC : O(10) ~= O(1)
    bool solve_optimal_2(string& s, int n) {
        unordered_set<char> st(10);
        st.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});

        int cnt1(0), cnt2(0);
        int i(0), j(n - 1);
        while (i < j) {
            if (st.find(s[i]) != st.end()) cnt1 ++;
            if (st.find(s[j]) != st.end()) cnt2 ++;
            i++, j--;
        }
        return cnt1 == cnt2;
    }
public:
    bool halvesAreAlike(string s) {
        // return solve_brute(s, s.length());

        // return solve_optimal_1(s, s.length());

        return solve_optimal_2(s, s.length());
    }
};