// https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    // TC : O(2^N) Where N = str.length()
    // SC : O(N) -> Recursive Depth
    int solve_rec(string& str, int idx, int sum) {
        if (idx == str.length()) return 1;
        
        int ans = 0;
        int currSum = 0;
        
        for (int i = idx; i < str.length(); i++) {
            currSum += str[i] - '0';
            
            if (currSum >= sum) {
                ans += solve_rec(str, i + 1, currSum);
            }
        }
        
        return ans;
    }
    
    int t[101][901];
    // TC : O(N^2 * M) Where M = Sum of all digits
    // SC : O(N * M)   Where N = Size of string 
    int solve_mem(string& str, int idx, int sum) {
        if (idx == str.length()) return 1;
        
        if (t[idx][sum] != -1) return t[idx][sum];
        
        int ans = 0;
        int currSum = 0;
        
        for (int i = idx; i < str.length(); i++) {
            currSum += str[i] - '0';
            
            if (currSum >= sum) {
                ans += solve_mem(str, i + 1, currSum);
            }
        }
        
        return t[idx][sum] = ans;
    }
	public:
	int TotalCount(string str){
	   // return solve_rec(str, 0, 0);
	   
	   memset(t, -1, sizeof(t));
	   return solve_mem(str, 0, 0);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends