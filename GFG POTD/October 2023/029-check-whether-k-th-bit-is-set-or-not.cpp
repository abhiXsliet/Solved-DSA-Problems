// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution
{
    private:
    // TC = O(K)
    bool solve(int n, int k) {
        int bit = 0;
        while(k+1) {
            bit = n & 1;
            n >>= 1;
            k--;
        }
        
        if (bit) return 1;
        else return 0;
    }
    
    // TC = O(1)
    bool solve_stl(int n, int k) {
        bitset<32> bits(n);
        
        return bits.test(k);
    }
    
    // TC = O(1)
    bool solve_one_liner(int n, int k) {
        return (n & (1 << k)) != 0;
    }
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // return solve(n, k);
        
        // return solve_stl(n, k);
        
        return solve_one_liner(n, k);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;//taking testcases
	while(t--)
	{
	    long long n;
	    cin>>n;//input n
	    int k;
	    cin>>k;//bit number k
	    Solution obj;
	    if(obj.checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}
// } Driver Code Ends