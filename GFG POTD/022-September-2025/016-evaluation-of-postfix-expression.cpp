// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isExp(string &str) {
        if (str.length() > 1) return false;
        return (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '^');
    }
    
    int floorDiv(int a, int b) {
        int res = a / b;
        if ((a ^ b) < 0 && a % b != 0) res--;
        return res;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    int evaluatePostfix(vector<string>& arr) {
        stack<int> stk;
        for (string &str : arr) {
            if (isExp(str)) {
                if (stk.size() >= 2) {
                    int ele1 = stk.top(); stk.pop();
                    int ele2 = stk.top(); stk.pop();
                    
                    if (str[0] == '+') {
                        stk.push(ele2 + ele1);
                    } else if (str[0] == '-') {
                        stk.push(ele2 - ele1);
                    } else if (str[0] == '*') {
                        stk.push(ele2 * ele1);
                    } else if (str[0] == '/') {
                        stk.push(floorDiv(ele2, ele1));
                    } else {
                        stk.push(pow(ele2, ele1));
                    }
                }
            } else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};