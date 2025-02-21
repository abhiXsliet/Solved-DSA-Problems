// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    bool approach_1(string &s) {
        stack<char> stk;
        for (char &ch : s) {
            if (!stk.empty()) {
                if (stk.top() == '(' && ch == ')' || 
                    stk.top() == '{' && ch == '}' || 
                    stk.top() == '[' && ch == ']') {
                    stk.pop();
                    continue;
                }                       
            } 
            stk.push(ch);
        }
        return stk.empty();
    }
    
    // TC : O(N)
    // SC : O(N)
    bool approach_2(string &s) {
        string str;
        for (char &ch : s) {
            if (!str.empty()) {
                if (str.back() == '(' && ch == ')' || 
                    str.back() == '{' && ch == '}' || 
                    str.back() == '[' && ch == ']') {
                    str.pop_back();
                    continue;
                }                       
            } 
            str.push_back(ch);
        }
        return str.empty();
    }
  public:
    bool isBalanced(string& s) {
        // return approach_1(s);
        return approach_2(s);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends