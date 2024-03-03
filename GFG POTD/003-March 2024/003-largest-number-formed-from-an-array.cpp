// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1



//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(N)
    string solve_approach_1(int n, vector<string>& arr) {
        auto cmp = [&](string& s1, string& s2) {
	        string r1 = s1 + s2;
	        string r2 = s2 + s1;
	        return r1 > r2;
	    };
	    
	    sort(begin(arr), end(arr), cmp);
	    
	    string result;
	    
	    for (auto& s : arr) {
	        result += s;
	    }
	    
	    return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    string solve_approach_2(int n, vector<string>& arr) {
        auto cmp = [&](string& s1, string& s2) {
	        string r1 = s1 + s2;
	        string r2 = s2 + s1;
	        return r1 < r2;
	    };
	    
	    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
	    
	    for (string& str : arr) 
	        pq.push(str);
	    
	    string result;
	    
	    while(!pq.empty()) {
	        string s = pq.top();
	        result  += s;
	        pq.pop();
	    }
	    
	    return result;
    }
public:
	// The main function that returns the arrangement with the largest value as string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string>& arr) {
	   // return solve_approach_1(n, arr);
	   
	   return solve_approach_2(n, arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends