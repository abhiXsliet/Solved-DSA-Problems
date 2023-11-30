// https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1



//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    // TC = O(log(N))
    // SC = O(1)
    int minimumStep(int n){
        int ans  = 0;
        while (n != 1) {
            if (n % 3 != 0) {
                n -= 1;
            }
            else {
                n /= 3;
            }
            ans ++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends