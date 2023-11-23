// https://leetcode.com/problems/longest-common-prefix/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(NM * log(N))
    // SC = O(M)
    string solve_brute(vector<string>& strs) {
        auto cmp = [&](string a, string b) {
            return a.length() < b.length();
        };

        // O(NM*log(N))
        sort(begin(strs), end(strs), cmp);
        
        string store = strs[0];

        if (store.empty())
            return "";

        string ans;
             
        int ptr1 = 0;
        int ptr2 = 0;

        // O(NM)
        for (int i = 0; i < strs.size(); i++) {
            ans = "";
            while (ptr1 < store.length() && 
                    ptr2 < strs[i].length() && 
                    store[ptr1] == strs[i][ptr2]) {
                        
                ans += store[ptr1];
                ptr1++, ptr2++;
            }
            store = ans;
            ptr1 = 0;
            ptr2 = 0;
        }

        return ans;
    }

    // TC = O(NM)
    // SC = O(M) -> to return the longest common prefix 
    string solve_better_1(vector<string>& strs) {
        int n = strs.size();

        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < n; j++) {
                // matching first word with others
                if (strs[0][i] != strs[j][i]) 
                    return ans;
            }

            ans += strs[0][i];
        }

        return ans;
    }

    // 
    int shortest_string(vector<string>& s, int n) {
        int minlength = INT_MAX, min_index;
        for (int i = 0; i < n; i++) {
            if (s[i].length() < minlength) {
                minlength = s[i].length();
                min_index = i;
            }
        }
        return min_index;
    }

    // TC = O(NM)
    // SC = O(1)
    string solve_better_2(vector<string>& s) {
        int n = s.size();
        // index of the smallest string
        int shortest_string_index = shortest_string(s, n);
 
        while (s[shortest_string_index].length() > 0) {
    
            int count = 0;
            for (int i = 0; i < n; i++) {
                // checking whether all strings have prefix
                // which is equal to smallest string
                if (s[i].find(s[shortest_string_index]) == 0) {
                    count++;
                }
            }
            // checking that all the string's
            // prefix is equal to smallest string
            // or not.
            if (count == n) {
                // cout << "longest common prefix is: " << endl;
                return s[shortest_string_index];
                break;
            }
            // deleting the last character
            // of the smallest string.
            s[shortest_string_index].pop_back();
        }
    
        return "";
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        // return solve_brute(strs);

        // return solve_better_1(strs);

        return solve_better_2(strs);
    }
};