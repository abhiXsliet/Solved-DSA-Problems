// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    string approach_1(string str) {
        string result;
        string temp;
        
        for (int i = str.length() - 1; i >= 0; i --) {
            if (str[i] == '.') {
                reverse(begin(temp), end(temp));
                result += temp + '.';
                temp = "";
            } else {
                temp += str[i];
            }
        }
        
        reverse(begin(temp), end(temp));
        result += temp;
        return result;
    }
    
    // TC : O(N)
    // SC : O(N) Where N = Length of str
    string approach_2(string str) {
        reverse(begin(str), end(str));
        stringstream ss(str);
        string word;
        string result;
        while(getline(ss, word, '.')) {
            reverse(begin(word), end(word));
            if (result.empty()) {
                result = word;
            } else {
                result += '.' + word;
            }
        }
        return result;
    }
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // return approach_1(str);
        
        return approach_2(str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends