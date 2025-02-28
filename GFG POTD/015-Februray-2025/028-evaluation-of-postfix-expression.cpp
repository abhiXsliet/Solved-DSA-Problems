// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int evaluate(vector<string>& arr) {
        stack<int> stk;
        for (string &s : arr) {
            if (s == "*" || s == "/" || s == "+" || s == "-") {
                if (stk.size() < 2) continue;
                
                int val1 = stk.top(); 
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                
                int calcVal = 0;
                if (s == "*") {
                    calcVal = val2 * val1;
                } else if (s == "/") {
                    calcVal = val2 / val1;
                } else if (s == "+") {
                    calcVal = val2 + val1;
                } else {
                    calcVal = val2 - val1;
                }
                stk.push(calcVal);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};

//{ Driver Code Starts.
int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends