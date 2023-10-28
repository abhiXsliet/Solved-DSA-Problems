// https://practice.geeksforgeeks.org/problems/bleak-numbers1552/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    int countSetBits(int n) {
        int cnt = 0;
        
        while (n > 0) {
            cnt += n & 1;
            n  >>= 1;
        }
        
        return cnt;
    }
    
    int solve_brute(int n) {
        for (int i = 1; i <= n; i++) {
	        if (i + countSetBits(i) == n) {
	            return 0;
	        }
	    }
	    return 1;
    }
    
    // TC = O(log(N) * log(N))
    int solve_optimal(int n) {
        // pow(10, 9) can be represented in 32-bits
        for (int i = max(n - 32, 1); i < n; i++) {
            if (i + countSetBits(i) == n)
                return 0;
        }
        return 1;
    }
public:
	int is_bleak(int n)
	{
	   // return solve_brute(n);
	   
	   return solve_optimal(n);
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends