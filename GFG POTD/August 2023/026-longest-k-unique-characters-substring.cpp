// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        
        int left = 0 ;
        int maxLen = 0;
        
        // edge case
        if(k > n) return -1;

        for(int right = 0; right < n; right++) {
            
            freq[s[right]]++;
            
            while (freq.size() > k) {
                
                freq[s[left]]--;
                
                if(freq[s[left]] == 0)
                    freq.erase( s[left] );
                    
                left++;
            }  
            
            if(freq.size() == k) 
                maxLen = max( maxLen, right - left + 1 );
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends