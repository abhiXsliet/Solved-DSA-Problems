// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(N) Where N = Length of String
    vector<int> approach_1(string str) {
        vector<int> result;
        stack<int> stk;
        int count = 1;
        
        for (char& ch : str) {
            if (ch == '(') {
                stk.push(count);
                result.push_back(count);
                count ++;
            } else if (ch == ')') {
                result.push_back(stk.top());
                stk.pop();
            }
        }
        
        return result;
    }
  public:
    vector<int> bracketNumbers(string str) {
        return approach_1(str);
    }
};


//{ Driver Code Starts.
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends