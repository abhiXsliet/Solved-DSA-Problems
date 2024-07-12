// https://leetcode.com/problems/maximum-score-from-removing-substrings/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    string strRemoval(string s, string removeStr) {
        int i = 0;  // used for writting on index-i whatever j reads

        for (int j = 0; j < s.length(); j ++) { // j is reading ptr which reads each char
            s[i] = s[j];    // writting on index-i whatever j reads
            i ++;

            if (i >= 2 && s[i - 2] == removeStr[0] && s[i - 1] == removeStr[1])
                i -= 2;
        }
        s.erase(begin(s) + i, end(s));
        return s;
    }

    // TC : O(N)
    // SC : O(N)
    string removeStr(string& s, string removeStr) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i ++) {
            if (!stk.empty() && stk.top() == removeStr[0] && s[i] == removeStr[1]) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }

        string newStr;
        while(!stk.empty()) {
            newStr += stk.top();
            stk.pop();
        }

        reverse(begin(newStr), end(newStr));
        return newStr;
    }

    // TC : O(N^2) Where N = Length of the string 's' & erase fn. will have TC as O(N)
    // SC : O(1)   
    int approach_1(string& s, int x, int y) {
        int maxPt = 0;
        bool xDeleted = 0;
        bool yDeleted = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && x > y) {
                maxPt += x;
                s.erase(s.begin() + i); // O(N)
                s.erase(s.begin() + i);
                i = i - 2 >= -1 ? i - 2 : -1;
                xDeleted = 1;

            } else if (s[i] == 'b' && s[i + 1] == 'a' && y > x) {
                maxPt += y;
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = i - 2 >= -1 ? i - 2 : -1;
                yDeleted = 1;
            }
        }

        for (int i = 0; i < s.length(); i ++) {
            if (xDeleted && s[i] == 'b' && s[i + 1] == 'a') {
                maxPt += y;
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = i - 2 >= -1 ? i - 2 : -1;

            } else if (yDeleted && s[i] == 'a' && s[i + 1] == 'b') {
                maxPt += x;
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = i - 2 >= -1 ? i - 2 : -1;

            } else if (s[i] == 'a' && s[i + 1] == 'b' || 
                       s[i] == 'b' && s[i + 1] == 'a') {
                if (s[i] == 'a') maxPt += x;
                if (s[i] == 'b') maxPt += y;
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i = i - 2 >= -1 ? i - 2 : -1;
            }
        }
        
        return maxPt;
    }

    // TC : O(N^2) Where N = Length of the string 's' & erase fn. will have TC as O(N)
    // SC : O(1) 
    int approach_1_new(string& s, int x, int y) {
        int maxPt = 0;
        bool xDeleted = 0;
        bool yDeleted = 0;

        auto processPair = [&](int i, int value) {
            maxPt += value;
            s.erase(i, 2);
            return max(-1, i - 2);
        };

        // Pass - 1 : Deleting Highest Value String First
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && x > y) {
                i = processPair(i, x);
                if (!xDeleted) xDeleted = 1;

            } else if (s[i] == 'b' && s[i + 1] == 'a' && y > x) {
                i = processPair(i, y);
                if (!yDeleted) yDeleted = 1;
            }
        }

        // Pass - 2 : Deleting Lowest Value String Second
        for (int i = 0; i < s.length(); i ++) {
            if (xDeleted && s[i] == 'b' && s[i + 1] == 'a') {
                i = processPair(i, y);

            } else if (yDeleted && s[i] == 'a' && s[i + 1] == 'b') {
                i = processPair(i, x);

            } else if (s[i] == 'a' && s[i + 1] == 'b' || 
                       s[i] == 'b' && s[i + 1] == 'a') {
                i = s[i] == 'a' ? processPair(i, x) : processPair(i, y);
            }
        }
        
        return maxPt;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(string s, int x, int y) {
        int n = s.length();
        int points = 0;
        
        string maxStr = x > y ? "ab" : "ba";
        string minStr = x < y ? "ab" : "ba";
        
        // Pass - 1 : remove the maxStr
        string afterFirstPass = removeStr(s, maxStr);
        int charsDeleted      = n - afterFirstPass.length();

        points += (charsDeleted / 2) * max(x, y);   // pairs of chars = charsDeleted / 2

        // Pass - 2 : remove the minStr
        string afterSecondPass = removeStr(afterFirstPass, minStr);
        charsDeleted           = afterFirstPass.length() - afterSecondPass.length();

        points += (charsDeleted / 2) * min(x, y);

        return points;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(string s, int x, int y) {
        int n = s.length();
        int points = 0;
        
        string maxStr = x > y ? "ab" : "ba";
        string minStr = x < y ? "ab" : "ba";
        
        // Pass - 1 : remove the maxStr
        string afterFirstPass = strRemoval(s, maxStr);
        int charsDeleted      = n - afterFirstPass.length();

        points += (charsDeleted / 2) * max(x, y);   // pairs of chars = charsDeleted / 2

        // Pass - 2 : remove the minStr
        string afterSecondPass = strRemoval(afterFirstPass, minStr);
        charsDeleted           = afterFirstPass.length() - afterSecondPass.length();

        points += (charsDeleted / 2) * min(x, y);

        return points;
    }
public:
    int maximumGain(string s, int x, int y) {
        // return approach_1(s, x, y);     // Brute      : Deleting Greedly

        // return approach_1_new(s, x, y); // Approach-1 : Written More Clearly

        // return approach_2(s, x, y);     // Using Stack: Better Approach

        return approach_3(s, x, y);     // whatever j read it will write on i
    }
};