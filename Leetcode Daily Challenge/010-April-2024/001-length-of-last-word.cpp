// https://leetcode.com/problems/length-of-last-word/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve_1(string& s, int n) {
        int ans = 0;
        bool flag = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ' && flag == 0) {
                continue;
            }
            while (i >= 0 && s[i] != ' ') {
                ans += 1;
                flag = 1;
                i --;
            }
            if (i >= 0 && s[i] == ' ') break;
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_2(string& s, int n) {
        int end = n - 1;
        while(s[end] == ' ') {
            end --;
        }
        int start = end;
        while(start >= 0 && s[start] != ' ') {
            start --;
        }
        return end - start;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_3(string& s, int n) {
        n = s.find_last_not_of(' ') + 1;
        s.erase(n);
        int newN = s.find_last_of(' ') + 1;
        return n - newN;
    }

    // TC : O(N)
    // SC : O(1)
    int solve_4(string& s, int n) {
        string ans;
        string str;
        stringstream iss(s);
        while(getline(iss, str, ' ')) {
            if (str != "") {
                ans = str;
            }
        }
        return ans.length();
    }

    // TC : O(N)
    // SC : O(1)
    int solve_5(string& s, int n) {
        string ans;
        stringstream iss(s);
        string word;
        while(iss >> word) {
            ans = word;
        }
        return ans.length();
    }
public:
    int lengthOfLastWord(string s) {
        // return solve_1(s, s.length());

        // return solve_2(s, s.length());

        // return solve_3(s, s.length());

        // return solve_4(s, s.length());

        return solve_5(s, s.length());
    }
};