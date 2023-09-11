// https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1



//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
private:
    // TC = O(sqrt(n))
    // SC = O(sqrt(n)) -> due to recursion depth
    bool solve_Rec(int n, int cnt) {
        //base case
        if (cnt > n) return 1;
        if (n % cnt == 0) return 0;
        
        return solve_Rec(n - n/cnt, cnt+1);
    }

    // TC = O(sqrt(n)), SC = O(1)
    bool solve_optimal(int n) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) return false;
            
            n = n - n/i; // remaining numbers
        }
        return true;
    }
public:
    bool isLucky(int n) {
        
        return  solve_Rec(n, 2);
        
        // return solve_optimal(n);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends