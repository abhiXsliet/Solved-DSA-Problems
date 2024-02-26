// https://www.geeksforgeeks.org/problems/power-set4302/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    // TC : O(2^n * nlog(n)) -> O(2^n) recursive calls, each taking O(n * log(n)) time due to string concatenation and multiset insertion.
    // SC : O(2^n * n) -> storage upto O(2^n) subsequences in the multiset, each having a maximum length of n.
    void generateSubsequence(string& s, multiset<string>& st, int n, int i, string curr) {
        if (i == n) {
            if (curr != "") {
                st.insert(curr);
            }
            return;
        }
        generateSubsequence(s, st, n, i + 1, curr);
        generateSubsequence(s, st, n, i + 1, curr + s[i]);
    }
    
    vector<string> approach_1(string& s) {
        int n = s.length();
	    multiset<string> st;
	    
	    generateSubsequence(s, st, n, 0, "");
	    
	    vector<string> result(begin(st), end(st));
	    
	    return result;
    }
	public:
	vector<string> AllPossibleStrings(string s){
	   return approach_1(s);
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends