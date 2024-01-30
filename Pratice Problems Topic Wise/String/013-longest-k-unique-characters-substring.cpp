// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1




//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(string s, int k) {
        int n = s.length();
        unordered_map<int, int> mpp;
        int maxLen = -1;
        
        int i = 0, j = 0;
        
        while (j < n) {
            mpp[s[j]]++;
            
            if (mpp.size() == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            else if (mpp.size() > k) {
                while(mpp.size() > k) {
                    mpp[s[i]] --;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        
        int left = 0 ;
        int maxLen = 0;
        
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
  public:
    int longestKSubstr(string s, int k) {
        // return solve_approach_1(s, k);;
        
        return solve_approach_2(s, k);
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