// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    // TC : O(M + N)
    // SC : O(N)
    string way_1(string& s, string& p) {
        int m = s.length();
        int n = p.length();
        
        unordered_map<char, int> mpp;
        for (char& ch : p) mpp[ch] ++;
        
        int count = mpp.size();
        int i = 0;
        int j = 0;
        int startIdx = -1;
        int minLen   = INT_MAX;
        
        while (j < m) {
            if (mpp.find(s[j]) != mpp.end()) {
                mpp[s[j]] --;
                
                if (mpp[s[j]] == 0) count --;
            }
            
            while (count == 0) {
                if (mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]] ++;
                    
                    if (mpp[s[i]] > 0) count ++;
                }
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                i ++;
            }
            j ++;
        }
        
        return minLen == INT_MIN ? "-1" : s.substr(startIdx, minLen);
    }
    
    // TC : O(M + N)
    // SC : O(N)
    string way_2(string& s, string& p) {
        int m = s.length();
        int n = p.length();
        
        unordered_map<char, int> mpp;
        for (char& ch : p) mpp[ch] ++;
        
        int i      = 0;
        int j      = 0;
        int count  = n;
        int minLen = INT_MAX;
        int stIdx  = -1;
        
        while (j < m) {
            if (mpp[s[j]] > 0) {
                count--;    // got the one required char
            }
            
            mpp[s[j]] --; // Always
            
            while (count == 0) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    stIdx  = i;
                }
                
                mpp[s[i]] ++;
                
                if (mpp[s[i]] > 0) {
                    count ++;
                }
                
                i ++;
            }
            
            j ++;
        }
        
        return minLen == INT_MIN ? "-1" : s.substr(stIdx, minLen);
    }
    
    // TC : O(M + N)
    // SC : O(1)
    string way_3(string& s, string& p) {
        int m = s.length();
        int n = p.length();
        
        vector<int> freq(26, 0);
        for (char& ch : p) freq[ch - 'a'] ++;
        
        int i      = 0;
        int j      = 0;
        int count  = n;
        int minLen = INT_MAX;
        int stIdx  = -1;
        
        while (j < m) {
            char ch = s[j];
            if (freq[ch - 'a'] > 0) {
                count--;    // got the one required char
            }
            
            freq[ch - 'a'] --; // Always
            
            while (count == 0) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    stIdx  = i;
                }
                
                freq[s[i] - 'a'] ++;
                
                if (freq[s[i] - 'a'] > 0) {
                    count ++;
                }
                
                i ++;
            }
            
            j ++;
        }
        
        return stIdx == -1 ? "-1" : s.substr(stIdx, minLen);
    }
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p) {
        // return way_1(s, p);
        
        // return way_2(s, p);
        
        return way_3(s, p);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends