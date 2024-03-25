// https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function template for C++

class Solution{
private:
    // TC : O(2^n)
    // SC : O(n)
    void solve(int n, int cnt_0, int cnt_1, string res, vector<string>& result) {
        if (n == 0) {
            result.push_back(res);
            return;
        }
        
        // add "1" to the string and increase its cnt
        solve(n-1, cnt_0, cnt_1 + 1, res+"1", result);
        
        if (cnt_1 > cnt_0) {    // add "0" to the string iff cnt_1 > cnt_0
            solve(n-1, cnt_0 + 1, cnt_1, res+"0", result);
        }
    }
public:	
	vector<string> NBitBinary(int n) {
	    vector<string> result;
	    solve(n, 0, 0, "", result);
	    return result;
	}
};


//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends