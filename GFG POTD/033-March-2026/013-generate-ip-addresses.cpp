// https://www.geeksforgeeks.org/problems/generate-ip-addresses/1/




#include <bits/stdc++.h>
using namespace std;

class Solution{
  private:
    // TC : O(N) Where N = str.length()
    // SC : O(M) Where M = length of string after split at '.'
    bool isValid(string& str) {
        int m = str.length();
        
        vector<string> store;
        string ex = "";
        
        for (int i = 0; i < m; i++) {
            if (str[i] == '.') {
                store.push_back(ex);
                ex = "";
            }
            else {
                ex += str[i];
            }
        }
        
        store.push_back(ex);
        
        for (int i = 0; i < store.size(); i++) {
            
            if (store[i].length() > 3 || stoi(store[i]) < 0 || stoi(store[i]) > 255)    
                return 0;
                
            if (store[i].length() > 1 && stoi(store[i]) == 0)
                return 0;
                
            if (store[i].length() > 1 && stoi(store[i]) != 0 && store[i][0] == '0')
                return 0;
            
        }
        return 1;
    }
    
    // TC : O(N * N * N)
    // SC : O(N)
    vector<string> brute(string& s, int n) {
        if (n > 12 && n < 4) return {};
        
        vector<string> result;
        string str = s;
        
        for (int i = 1; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    
                    str = str.substr(0, k) + "." + str.substr(k);
                    str = str.substr(0, j) + "." + str.substr(j);
                    str = str.substr(0, i) + "." + str.substr(i);
                    
                    if (isValid(str)) {
                        result.push_back(str);
                    }
                    
                    str = s; 
                }
            }
        }
        
        return result;
    }
    
    // TC : O(N^4)  Where n is the length of the string. 
    //              At worst,Check all possible combinations by dividing the string into 4 parts
    // SC : O(N) This is because we need to store the temporary string temp
    void solve(string& s, int i, int n, int level, string temp, vector<string>& res) {
        //  It means we have divided the string into 4 parts (since level starts from 1 and ends at 5)
        if (i == (n + 1) && level == 5) {
            res.push_back(temp.substr(1));
        }
        
        // Digits of a number ranging 0-255 can lie only between 0-3digits
        for (int k = i; k < i + 3 && k <= n; k++) {
            string sub = s.substr(i, k - i + 1);
            
            // Return if string starting with '0' or it is greater than 255
            if ((sub.length() > 1 && s[i] == '0') || (stoi(sub) > 255))
                return ;
            
            // Return if string starting with '0' or it is greater than 255
            solve(s, k + 1, n, level + 1, temp + '.' + sub, res);
        }
    }
  public:
    vector<string> generateIp(string &s) {
        // return brute(s, s.length());
        
        vector<string> res;
        solve(s, 0, s.length() - 1, 1, "", res);
        return res;
    }

};