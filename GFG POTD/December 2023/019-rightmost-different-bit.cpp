// https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    // TC : O(max(logM, logN))
    // SC : O(1)
    // Approach : Convert the no. into its binary and check for different bit
    int solve_brute(int m, int n) {
        int cnt = 1;
        while(m != 0 || n != 0) {
            if (m % 2 != n % 2) return cnt;
            cnt++;
            m /= 2, n /= 2;
        }
        return -1;
    }
    
    // TC : O(1)
    // SC : O(1)
    int solve_optimal_1(int m, int n) {
        if (m == n) return -1;
        
        int cnt  = 1;
        int mask = 1;
        
        while(cnt <= 32) {
            if ((mask & m) != (mask & n)) 
                return cnt;
            cnt++;
            mask = mask << 1;
        }
        return -1;
    }
    
    // TC : O(1)
    // SC : O(1)
    int solve_optimal_2(int m, int n) {
        if (n == m) return -1;
        
        int cnt  = 1;
        int mask = 1;
        
        while((mask & m) == (mask & n)) {
            cnt++;
            mask <<= 1;
        }
        return cnt;
    }
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // return solve_brute(m, n);
        
        // return solve_optimal_1(m, n);
        
        return solve_optimal_2(m, n);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends