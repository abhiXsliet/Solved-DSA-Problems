// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function template for C++
class Solution{
private:
    // TC : O(N)
    // SC : O(N)
    string solve_approach_1(string str) {
        int n = str.length();
	    unordered_set<char> st;
	    string res;
	    for (int i = 0; i < n; i++) {
	        if (st.find(str[i]) == st.end()) {
	            res += str[i];
	            st.insert(str[i]);
	        }
	    }
	    return res;
    }
public:
	string removeDuplicates(string str) {
	    return solve_approach_1(str);
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends