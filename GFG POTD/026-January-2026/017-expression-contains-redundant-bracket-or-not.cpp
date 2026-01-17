// https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    bool checkRedundancy(string &s) {
        int n = s.length();
        stack<char> stk;
        
        for (char &ch : s) {
            if (ch != ')') {
                stk.push(ch);
            } else {
                bool hasOpr = false;
                while (!stk.empty() && stk.top() != '(') {
                    char topCh = stk.top();
                    stk.pop();
                    if (topCh == '+' || topCh == '-' || topCh == '*' || topCh == '/') {
                        hasOpr = true;
                    }
                }
                
                // pop '('
                stk.pop();
                
                // if there's no opr character then there's redundant char
                if (!hasOpr) return true;
            }
        }
        
        return false;
    }
};
