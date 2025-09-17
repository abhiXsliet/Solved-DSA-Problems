// https://www.geeksforgeeks.org/problems/decode-the-string2444/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }
    
    int getDigit(stack<char> &stk) {
        int result = 0, base = 1;
        while (!stk.empty() && isDigit(stk.top())) {
            result = (stk.top() - '0') * base + result;
            stk.pop();
            base *= 10;
        }
        return result;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    string decodedString(string &s) {
        stack<char> stk;
        for (char &ch : s) {
            if (ch == ']') {
                // collect substring inside [...]
                string newStr;
                while (!stk.empty() && stk.top() != '[') {
                    newStr += stk.top();
                    stk.pop();
                }
                reverse(begin(newStr), end(newStr));
                
                // pop the '['
                if (!stk.empty() && stk.top() == '[') stk.pop();
                
                int times = getDigit(stk);
                
                string extended;
                for (int i = 0; i < times; i ++) {
                    extended += newStr;
                }

                for (char &c : extended) {
                    stk.push(c);
                }
            } else {
                stk.push(ch);
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
};