// https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1



//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    private:
    // TC = O(N), SC = O(1)
    long long fib (int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        
        long long a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b; 
            b = c;
        }
        return b;
    }
    
    // TC = O(N), SC = O(N)
    vector<long long> solve_basic(int n) {
        vector<long long> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(fib(i));
        }
        return ans;
    }
    
    // TC = O(N), SC = O(N)
    vector<long long> solve_oneLiner(int n) {
        vector<long long> ans(n, 1);
        for (int i = 2; i < n; i++) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans;
    }
    
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        // return solve_basic(n);
        
        return solve_oneLiner(n);
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends