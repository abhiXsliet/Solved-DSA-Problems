// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int result = 0;
	    int k = pat.length();
	    int n = txt.length();
	    int i = 0, j = 0;
	    
	    unordered_map<char, int> mpp;
	    for (char& ch : pat) {
	        mpp[ch] ++;
	    }
	    int count = mpp.size();
	    
	    while (j < n) {
	        if (mpp.find(txt[j]) != mpp.end()) {
	            mpp[txt[j]]--;
	            
	            if (mpp[txt[j]] == 0) count --;
	        }
	        else {
	            mpp[txt[j]] ++;
	        }
	        
	        if (j - i + 1 > k) {
	            if (mpp.find(txt[i]) != mpp.end()) {
	                mpp[txt[i]] ++;
	            }
	            
	            if (mpp[txt[i]] == 1) count ++;
	            i++;
	        }
	        
	        if (j - i + 1 == k) {
	            if (count == 0) result ++;
	        }
	        j ++;
	    }
	    return result;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends