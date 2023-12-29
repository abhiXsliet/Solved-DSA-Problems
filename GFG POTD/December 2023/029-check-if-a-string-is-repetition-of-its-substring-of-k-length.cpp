// https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    // TC : O(N)
    // SC : O(N)
    // SLIDING WINDOW to fill the map
    int solve_approach_1(int n, string& s, int k) {
        // To convert string 's' into substrings of length 'k', 
        // it must be a multiple of 'k' as per given condition
        if (n % k != 0) 
            return false;
            
        unordered_map<string, int> mpp;
        
        // slide window i+=k as per given condn i % k == 0
        for (int i = 0; i < n; i+=k) {
            // mpp[s.substr(i, k)]++;   // one liner
            
            string temp = "";
            for (int j = i; j < i+k; j++) {
                temp += s[j];
            }
            mpp[temp]++;
        }
        
        // To convert 's', we must choose only 2-substrings of len 'k'
        if (mpp.size() > 2) 
            return false;
            
        return true;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_approach_2(int n, string& s, int k) {
        if (n % k != 0) 
            return 0;
            
        unordered_map<string, int> mpp;
        
        string temp = "";
        temp       += s[0];
        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                mpp[temp]++;
                temp = "";
            }
            temp += s[i];
        }
        // insert last substr of k len into map
        mpp[temp]++;
        
        if (mpp.size() > 2)
            return false;
        
        return true;
    }
public:
	int kSubstrConcat (int n, string s, int k)
	{
	    return solve_approach_1(n, s, k);
	   
	   //return solve_approach_2(n, s, k);
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends