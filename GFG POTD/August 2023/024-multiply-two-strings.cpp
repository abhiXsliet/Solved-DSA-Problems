// https://practice.geeksforgeeks.org/problems/multiply-two-strings/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> store(n+m, 0);
        
        // check if the first char in strings is -ve
        int a = s1.at(0) == '-' ? -1 : 0;
        int b = s2.at(0) == '-' ? -1 : 0;
        
        for(int i = m - 1; i >= 0; i--) {
            if(s1[i] != '-') { 
                int carry = 0;
                int k = i + n; // n + m - 1;
                
                for(int j = n - 1; j >= 0; j--) {
                    
                    if(s2[j] != '-') {
                        int product = (s1[i] - '0') * (s2[j] - '0') + carry + store[k];
                        carry = product / 10;
                        store[k] = product % 10;
                        k--;
                    }
                    
                }
                if(carry > 0) store[k] = carry;
            }
        }
        
        string res = "";
        bool flag = 1;
        for(int i = 0; i < n+m; i++) {
            while(i < n+m && flag == 1 && store[i] == 0) {
                i++;
            }
            flag = false;
            if(i < n+m) res += to_string(store[i]);
        }
        
        if(a >= 0 && b < 0 || a < 0 && b >= 0) 
            res = "-" + res;
            
        if(res.length() == 0) 
            return "0";
        
        return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends