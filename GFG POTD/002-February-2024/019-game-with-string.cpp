// https://www.geeksforgeeks.org/problems/game-with-string4100/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // TC : O(N)
    // SC : O(N + k * log(p)) where n = length of string
    //                              p = number of distinct alphabets 
    //                              k = number of alphabets to be removed. 
    int minValue(string s, int k){
        int n = s.length();
        
        vector<int> freq(26, 0);
        for (char& ch : s) {
            freq[ch - 'a'] ++;
        }
        
        priority_queue<int> maxHeap;
        
        for (int& cnt : freq) {
            maxHeap.push(cnt);
        }
        
        while (k) {
            int val = maxHeap.top();
            maxHeap.pop();
            
            val -= 1;
            maxHeap.push(val);
            k -= 1;
        }
        
        int ans = 0;
        while (!maxHeap.empty()) {
            int val = maxHeap.top();
            maxHeap.pop();
            ans += (val * val);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends