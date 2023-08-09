// https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1



//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        long long int ans = 1;
        // for 'N' to be even
        while(N % 2 == 0) {
            ans = 2;
            N /= 2;
        }
        
        // for 'N' to be odd
        for(int i = 3; i <= sqrt(N); i += 2) {
            
            while(N % i == 0) {
                ans = i;
                N /= i;
            }
        }
        // 'N' itself a prime number
        if(N > 2)
            ans = N;
            
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends