// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    unsigned int solve_better(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt++;
            if (num % 2 == 1) break;
            num /= 2;
        }
        return cnt;
    }
    
    // TC = O( log(N) )
    // SC = O( 1 )
    unsigned int solve_optimal(int num) {
        int cnt = 0, mask = 1;
        while (num) {
            if (num & mask) {
                cnt++;
                break;
            }
            cnt  += 1;
            num >>= 1;
        }
        return cnt;
    }
    
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // return solve_better(n);
        
        return solve_optimal(n);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends