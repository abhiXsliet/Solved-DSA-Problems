// https://leetcode.com/contest/weekly-contest-388/problems/shortest-uncommon-substring-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(n * (m^3 + m^2*log(m) + m^2*n*m)) ~= O(n^2 * m^2)
    // SC : O(n * m^2) Where N = arr.size() & M = max length of individual strings of arr
    vector<string> approach_1(vector<string>& arr, int n) {
        vector<string> res(n, "");
        for (int i = 0; i < n; i++) {
            vector<string> st;
            
            int m = arr[i].length();
            // O(m^3)
            for (int j = 0; j < m; j++) {
                for (int len = 1; len <= m - j; len++) {
                    string substr = arr[i].substr(j, len);
                    st.push_back(substr);
                }
            }
            
            auto cmp = [&](string s1, string s2) {
                if (s1.length() == s2.length())
                    return s1 < s2;
                return s1.length() < s2.length();
            };
            sort(begin(st), end(st), cmp); // O(m^2 * log(m))
            
            for (auto& str : st) {  // O(m^2)
                bool flag = 0;
                for (int k = 0; k < n; k++) { // O(n)
                    if (k != i && (arr[k].find(str) != string::npos)) { // O(m)
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    res[i] = str;
                    break;
                }
            }
        }
        return res;
    }

    // TC : O(n^2 * m^2)
    // SC : O(n*m^2)
    vector<string> approach_2(vector<string>& arr, int n) {
        vector<string> answer(n, string(21, 'z'));
        for (int i = 0; i < n; ++i) {
            unordered_set<string> substrings;
            for (int len = 1; len <= arr[i].size(); ++len) {
                for (int start = 0; start + len <= arr[i].size(); ++start) {
                    substrings.insert(arr[i].substr(start, len));
                }
            }
            for (const string& s : substrings) {
                bool unique = true;
                for (int j = 0; j < n; ++j) {
                    if (i != j && arr[j].find(s) != string::npos) {
                        unique = false;
                        break;
                    }
                }
                if (unique && (s.size() < answer[i].size() || (s.size() == answer[i].size() && s < answer[i]))) {
                    answer[i] = s;
                }
            }
            if (answer[i] == string(21, 'z')) { 
                answer[i] = "";
            }
        }
        return answer;
    }

    // TC : ~O(n^4)
    // SC : O(n^3) storing all unique substrings in seen (In worst case we will have n^2 substrings from each string (suppose of length n) and let's we have n string in total
    vector<string> approach_3(vector<string>& arr, int n) {
        vector<string> answer(n);
        unordered_map<string, int> mpp;
        
        for (string& s : arr) {
            
            unordered_set<string> seen;     // individual string substrings should be present only once
            for (int i = 0; i < s.length(); i++) {
                for (int len = 1; len <= s.length(); len++) {
                    string substr = s.substr(i, len);
                    if (seen.find(substr) == seen.end()) {
                        seen.insert(substr);
                        mpp[substr] ++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            string shortest = "";
            
            for (int j = 0; j < arr[i].length(); j++) {
                for (int len = 1; len <= arr[i].length(); len++) {
                    string substr = arr[i].substr(j, len);
                    
                    if (mpp[substr] == 1 && (shortest == "" || shortest.length() > substr.length() || 
                        (shortest.length() == substr.length() && shortest > substr) ) ) {
                        shortest = substr;
                    }
                }
            }

            answer[i] = shortest;
        }
        return answer;
    }
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        // return approach_1(arr, arr.size());

        // return approach_2(arr, arr.size());
        
        return approach_3(arr, arr.size());
    }
};