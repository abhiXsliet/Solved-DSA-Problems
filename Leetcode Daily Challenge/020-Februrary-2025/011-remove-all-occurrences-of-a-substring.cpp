// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        // TC : O(M)
        // SC : O(M)
        int searchPartInS(string &s, string &part, vector<int>& lps) {
            int m = s.length(), n = part.length();
            int i = 0, j = 0;
            while (i < m) {
                if (s[i] == part[j]) {
                    i ++, j ++;
                } else {
                    if (j - 1 > 0) j = lps[j - 1];
                    else i ++;
                }
                if (j == n) {
                    return (i - j);   // index at which there is match
                }
            }
            return -1;
        }
    
        // TC : O(N)
        // SC : O(1)
        vector<int> getLps(string &part) {
            int n = part.length();
            vector<int> lps(n, 0);
            int i = 1;
            int len = 0;
            while (i < n) {
                if (part[i] == part[len]) {
                    len   += 1;
                    lps[i] = len;
                    i ++;
                } else {
                    if (len - 1 >= 0) len = len - 1;  // len = lps[len - 1];
                    else {
                        lps[i] = 0;
                        i ++;
                    }
                }
            }
            return lps;
        }
    
        // TC : O(M + N)
        // SC : O(1)
        bool isPartAvailableAsSubstr(string str, string part, int n) {
            int m = str.length();
            int i = n - 1, j = m - 1;
            while (!str.empty() && i >= 0 && j >= 0 && str[j] == part[i]) {
                i --, j --;
            }
            return i == -1;
        }
    
        // TC : O(N)
        // SC : O(N)
        bool partAvailableAsSubstr(stack<char>& stk, int n, string part) {
            int i = n - 1;
            string storePoppedChars;
            while (!stk.empty() && i >= 0 && stk.top() == part[i]) {
                storePoppedChars += stk.top();
                stk.pop();
                i --;
            }
            int m = storePoppedChars.length();
            for (int i = m - 1; i >= 0; i --) {
                stk.push(storePoppedChars[i]);
            }
            return i == -1;
        }
    
        // TC : O(M * M) due to repeated searching and shifting where m = s.length()
        // SC : O(1)
        string approach_1(string s, string part) {
            for (int i = 0; i < s.length(); i ++) {
                if (s.substr(i, part.length()) == part) {
                    s.erase(i, part.length());
                    i = -1;
                }
            }
            return s;
        }
    
        // TC : O(M * N) Where M = s.length(), N = part.length()
        // SC : O(1)
        string approach_2(string s, string part) {
            while (!s.empty() && s.find(part) < s.length()) {
                s.erase(s.find(part), part.length());
            }
            return s;
        }
    
        // TC : O(M * N) Where M = s.length(), N = part.length()
        // SC : O(M)
        string approach_3(string s, string part) {
            int n = part.length();
            stack<char> stk;
            for (char &ch : s) {
                stk.push(ch);
                if (stk.size() >= part.size() && partAvailableAsSubstr(stk, n, part)) {
                    for (int i = 0; i < n; i ++) {
                        stk.pop();
                    }
                }
            }
            string result;
            while (!stk.empty()) {
                result += stk.top();
                stk.pop();
            }
            reverse(begin(result), end(result));
            return result;
        }
    
        // TC : O(M * N)
        // SC : O(M)
        string approach_4(string s, string part) {
            int n = part.length();
            string str;
            for (char &ch : s) {
                str += ch;
                if (str.length() >= part.length() && isPartAvailableAsSubstr(str, part, n)) {
                    for (int i = 0; i < n; i ++) {
                        str.pop_back();
                    }
                }
            }
            return str;
        }
    
        // TC : O(M + N)
        // SC : O(M)
        string approach_5(string s, string part) {
            vector<int> lps = getLps(part);     // O(N)
            int times = (s.length() / part.length()) + 1; // no. of times part can be available as a substr in s
    
            while (times --) {
                int foundAtIdx = searchPartInS(s, part, lps);
                if (foundAtIdx == -1) {
                    return s;
                } else {
                    s = s.erase(foundAtIdx, part.length());
                }
            }
            
            return s;
        }
    public:
        string removeOccurrences(string s, string part) {
            // return approach_1(s, part);  // Brute : Input Modified
            // return approach_2(s, part);  // Better: Input Modified
            // return approach_3(s, part);  // Using Stack : Input Intact
            // return approach_4(s, part);  // Using String: Input Intact
            return approach_5(s, part);  // Using KMP : Input Modified
        }
    };