// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    // TC = O(N)
    bool solve_1(long long n) {
        while(n != 0) {
            if (n == 0 || n == 1) return 1;
            
            if(n % 2 == 0) n /= 2;
            else return 0;
        }
        return 0;
    }
    
    // TC = O(1)
    bool solve_2(long long n) {
        if (n == 0) return 0;
        else if ( (n & (n -1)) == 0 ) return 1;
        else return 0;
    }
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // return solve_1(n);
        
        return solve_2(n);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends