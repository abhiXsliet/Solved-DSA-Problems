// https://www.geeksforgeeks.org/problems/decode-the-string2444/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
/*
    TC : O(N)
    SC : O(N)
    -- Approach : 1 Use two stacks (one for numbers, one for characters) --
    1. On encountering ']', pop characters until '[' is found, repeat the substring n times (from number stack), 
    and push repeated string back (in reverse), ensuring the final stack contains the decoded result.
*/
    string approach_1(string &s) {
        int n = s.length();
        stack<int> stk1;     // this will store all the integers of string s
        stack<char> stk2;    // this will store all the chars of the string s
        
        for (int i = 0; i < n; i ++) {
            if (isdigit(s[i])) {
                string num;
                while (isdigit(s[i])) {
                    num += s[i];
                    i ++;
                }
                stk1.push(stoi(num));
                i --;   // since for loop doing i ++;
            } else { 
                // if we encounter ']' then start popping until stack encounter a closing '['
                if (s[i] == ']') {
                    string newS;
                    while (!stk2.empty() && stk2.top() != '[') {
                        newS = stk2.top() + newS;    // for reversal
                        stk2.pop();
                    }
                    if (!stk2.empty()) stk2.pop(); // to remove '['
                    
                    // now populate newS 'len' time, get len from stk1.top()
                    if (!stk1.empty()) {
                        int len = stk1.top();
                        stk1.pop();
                        string repeat = newS;
                        newS = "";
                        for (int i = 0; i < len; i ++) {
                            newS += repeat;
                        }
                        
                        // now push all the newS chars to the stack 2
                        for (char &c : newS) {
                            stk2.push(c);
                        }
                    }
                } else {
                    stk2.push(s[i]);
                }
            }
        }
        
        string result;
        while (!stk2.empty()) {
            result = stk2.top() + result;
            stk2.pop();
        }
        return result;
    }

/*
    TC : O(N)
    SC : O(N)
    -- Approach : 2 (Key Observation : store number and chars in single stack, before '[' (stack.top() contains a number) --
*/
    string approach_2(string &s) {
        int n = s.length();
        stack<char> stk2;    // this will store all the chars of the string s
        
        for (int i = 0; i < n; i ++) {
            if (isdigit(s[i])) {
                stk2.push('$');
                while (isdigit(s[i])) {
                    stk2.push(s[i]);
                    i ++;
                }
                stk2.push('$');
                i --;   // since for loop doing i ++;
            } else { 
                // if we encounter ']' then start popping until stack encounter a closing '['
                if (s[i] == ']') {
                    string newS;
                    while (!stk2.empty() && stk2.top() != '[') {
                        newS = stk2.top() + newS;    // for reversal
                        stk2.pop();
                    }
                    if (!stk2.empty()) stk2.pop(); // to remove '['
                    
                    // now takeout the number occured before '['
                    string length;
                    stk2.pop(); // pop last '$'
                    while (!stk2.empty() && stk2.top() != '$') {
                        length = stk2.top() + length;
                        stk2.pop();
                    }
                    stk2.pop(); // pop initial '$'
                    
                    int len = stoi(length);
                    string repeat = newS;
                    newS = "";
                    for (int i = 0; i < len; i ++) {
                        newS += repeat;
                    }
                    
                    // now push all the newS chars to the stack 2
                    for (char &c : newS) {
                        stk2.push(c);
                    }
                } else {
                    stk2.push(s[i]);
                }
            }
        }
        
        string result;
        while (!stk2.empty()) {
            result = stk2.top() + result;
            stk2.pop();
        }
        return result;
    }

/*
    TC : O(N)
    SC : O(N)
    -- Approach : 3 (No Stack (Used string as a stack)) --
*/
    string approach_3(string &s) {
        int n = s.length();
        string stk2;    // this will store all the chars of the string s
        
        for (int i = 0; i < n; i ++) {
            if (isdigit(s[i])) {
                stk2 += '$';
                while (isdigit(s[i])) {
                    stk2 += s[i];
                    i ++;
                }
                stk2 += '$';
                i --;   // since for loop doing i ++;
            } else { 
                // if we encounter ']' then start popping until stack encounter a closing '['
                if (s[i] == ']') {
                    string newS;
                    while (!stk2.empty() && stk2.back() != '[') {
                        newS = stk2.back() + newS;    // for reversal
                        stk2.pop_back();
                    }
                    if (!stk2.empty()) stk2.pop_back(); // to remove '['
                    
                    // now takeout the number occured before '['
                    string length;
                    stk2.pop_back(); // pop last '$'
                    while (!stk2.empty() && stk2.back() != '$') {
                        length = stk2.back() + length;
                        stk2.pop_back();
                    }
                    stk2.pop_back(); // pop initial '$'
                    
                    int len = stoi(length);
                    string repeat = newS;
                    newS = "";
                    for (int i = 0; i < len; i ++) {
                        newS += repeat;
                    }
                    
                    // now copy all the newS chars to the stk2
                    stk2 += newS;
                } else {
                    stk2 += s[i];
                }
            }
        }
        
        return stk2;
    }
  public:
    string decodedString(string &s) {
        // return approach_1(s);    // 2-Stack : Stack-1 (contains integers), Stack-2 (contains all chars except integers)
        
        // return approach_2(s);    // 1-Stack : pushed '$' before starting and ending of a number and all the other chars as usual
    
        return approach_3(s);    // No stack, Used string as a stack
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends